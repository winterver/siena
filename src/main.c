/**
 * Copyright (c) 2024 winterver
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

/**
 * File              : main.c
 * Author            : winterver
 * Date              : 2024.11.28
 * Last Modified Date: 2024.11.29
 * Last Modified By  : winterver
 */

#include <stddef.h>
#include <printk.h>
#include "stub.h"

// Halt and catch fire function.
static void hcf(void) {
    for (;;) {
        asm ("hlt");
    }
}

void kmain(void) {
    if (!LIMINE_BASE_REVISION_SUPPORTED ||
        framebuffer_request.response == NULL ||
        framebuffer_request.response->framebuffer_count < 1)
    {
        hcf();
    }

    init_video(framebuffer_request.response->framebuffers[0]);
    init_serial();

    printk("Hello World!\n");

    hcf();
}
