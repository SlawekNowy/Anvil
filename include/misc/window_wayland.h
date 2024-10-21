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

/** Implements a simple window wrapper for Linux (Wayland) environments.
 *
 *  NOTE: This directly uses wayland API for now. Delegate to runtime after debugging.
 **/
#ifndef WINDOW_WAYLAND_H
#define WINDOW_WAYLAND_H

#include "misc/window.h"
#include <wayland-client.h>

namespace Anvil
{
    class WindowWayland : public Window
    {
    public:
        /* Public functions */
        static Anvil::WindowUniquePtr create(const std::string&             in_title,
                                             unsigned int                   in_width,
                                             unsigned int                   in_height,
                                             bool                           in_closable,
                                             Anvil::PresentCallbackFunction in_present_callback_func,
                                             bool                           in_visible);

        static Anvil::WindowUniquePtr create(wl_display* in_display_ptr,
                                             WindowHandle      in_window_handle);

        virtual ~WindowWayland();

        virtual void close();
        virtual void run();

        /* Returns window's platform */
        WindowPlatform get_platform() const
        {
            return WINDOW_PLATFORM_WAYLAND;
        }

        /* Tells if it's a dummy window (offscreen rendering thus no WSI/swapchain involved) */
        virtual bool is_dummy()
        {
            return false;
        }

        /** Return the connection to display this window is connected to.*/
        
        virtual void* get_connection() const
        {
            return m_display_ptr;
        }
        

    private:
        WindowWayland(const std::string&             in_title,
                  unsigned int                   in_width,
                  unsigned int                   in_height,
                  bool                           in_closable,
                  Anvil::PresentCallbackFunction in_present_callback_func);

       WindowWayland(wl_display*              in_connection_ptr,
                 WindowHandle                   in_window_handle);

        /** Creates a new system window and prepares it for usage. */
        bool init           (const bool& in_visible);
        //bool init_connection();

        /* Private variables */
        /*
        xcb_intern_atom_reply_t* m_atom_wm_delete_window_ptr;
        xcb_connection_t*        m_connection_ptr;
        xcb_screen_t*            m_screen_ptr;
        xcb_key_symbols_t*       m_key_symbols;
        XCBLoader                m_xcb_loader;
        */
        wl_display*  m_display_ptr;
        WaylandLoader m_wayland_loader;
    };
}; /* namespace Anvil */

#endif /* WINDOW_XCB_H */