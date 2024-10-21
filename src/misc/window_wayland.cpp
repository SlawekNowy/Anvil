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
#include "misc/window_wayland.h"

Anvil::WindowUniquePtr Anvil::WindowWayland::create(const std::string &in_title, unsigned int in_width, unsigned int in_height, bool in_closable, Anvil::PresentCallbackFunction in_present_callback_func, bool in_visible)
{
    return Anvil::WindowUniquePtr();
}

/** Please see header for specification */
Anvil::WindowWayland::WindowWayland(const std::string&             in_title,
                            unsigned int                   in_width,
                            unsigned int                   in_height,
                            bool                           in_closable,
                            Anvil::PresentCallbackFunction in_present_callback_func)
    :Window(in_title,
            in_width,
            in_height,
            in_closable,
            in_present_callback_func)
{
    m_window_owned   = true;
}
