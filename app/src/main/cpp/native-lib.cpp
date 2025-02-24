#include <jni.h>
#include <string>
#include <thread>
#include <cstdint>
#include <vector>
#include "Engine/Includes.hpp"

//void
void (*Update)(void *) = nullptr;
void new_Update(void* self) {

    //Do your code stuff

    //makes the original code run
    Update(self);
}

//bool
bool (*booleanthing)(void *) = nullptr;
bool new_booleanthing(void* self) {
    return true;
}

//float
float (*floatthing)(void *) = nullptr;
float new_floatthing(void* self) {
    return 0.0f;
}

//int
int (*intthing)(void *) = nullptr;
int new_intthing(void* self) {
    return 1;
}

__attribute__ ((constructor))
void lib_main() {
    std::thread([]() {
        ProcMap map;
        do {
            map = KittyMemory::getElfBaseMap("libil2cpp.so");
            sleep(1);
        } while (!map.isValid() && !map.isValidELF());

        if (Il2Cpp::Init("libil2cpp.so") == -1) {
            LOGE("Il2Cpp::Init Failed!");
            return;
        }

        //This gets the pointer
        //Assembly, Namespace, Class, MethodName, Number of Parameters
        setPointer(Update, "Assembly-CSharp.dll", "Namespace", "Player", "Update", 0);

        //Hooks the method
        setHook(Update, "Update");

    }).detach();
}
