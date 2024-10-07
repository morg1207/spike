// dynamic_load.cpp
#include <dlfcn.h>
#include <iostream>

typedef void (*HelloFunc)();

int main() {
    void* handle = dlopen("./libmylib.so", RTLD_LAZY);
    if (!handle) {
        std::cerr << "Unable to load library: " << dlerror() << std::endl;
        return 1;
    }

    // Clear any existing error
    dlerror();

    HelloFunc hello = (HelloFunc)dlsym(handle, "hello");
    const char* dlsym_error = dlerror();
    if (dlsym_error) {
        std::cerr << "Unable to load symbol: " << dlsym_error << std::endl;
        dlclose(handle);
        return 1;
    }

    hello();
    dlclose(handle);

    return 0;
}
