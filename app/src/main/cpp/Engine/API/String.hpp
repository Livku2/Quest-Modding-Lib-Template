struct Il2CppString {
    void *klass;
    void *monitor;
    int32_t length;
    uint16_t start_char;

    int getLength() {
        return length;
    }

    char *getChars() {
        return (char *)&start_char;
    }

    const char* CString();
    const wchar_t* WCString();
};