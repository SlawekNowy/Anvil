//
// Copyright (c) 2024 MrSoup678 All rights reserved.
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//
#include "misc/wayland_loader.h"
#include <cstring>
#include <dlfcn.h>
using std::memset;

WaylandLoader::WaylandLoader() {

    memset(m_library_handles,
           0,
           sizeof(m_library_handles));

    memset(&m_funcs, 
           0,
           sizeof(m_funcs));
}

WaylandLoader::~WaylandLoader() {

    if (m_library_handles[WAYLAND_LOADER_LIBRARIES_CLIENT] != nullptr)
    {
        dlclose(m_library_handles[WAYLAND_LOADER_LIBRARIES_CLIENT]);
    }
}

Result WaylandLoader::init() {  Result result = Result::Success;

    if (m_initialized == false)
    {
        // resolve symbols from libxcb-keysyms.so.1
        m_library_handles[WAYLAND_LOADER_LIBRARIES_CLIENT] = dlopen("libxcb-keysyms.so.1",
                                                                     RTLD_LAZY);

        if (m_library_handles[WAYLAND_LOADER_LIBRARIES_CLIENT] == nullptr)
        {
            result = Result::ErrorUnavailable;
        }
        else
        {
            m_funcs.pfn_wl_display_connect        = reinterpret_cast<PFN_wl_display_connect>       (dlsym(m_library_handles[WAYLAND_LOADER_LIBRARIES_CLIENT],
                                                                                                    "wl_display_connect") );
            m_funcs.pfn_wl_display_disconnect = reinterpret_cast<PFN_wl_display_disconnect>(dlsym(m_library_handles[WAYLAND_LOADER_LIBRARIES_CLIENT],
                                                                                                    "wl_display_disconnect") );
        }

       
        if (result == Result::Success)
        {
            m_initialized = true;
        }
    }

    return result;
 }

