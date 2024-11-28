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
 * File              : port.h
 * Author            : winterver
 * Date              : 2024.11.28
 * Last Modified Date: 2024.11.28
 * Last Modified By  : winterver
 */

#ifndef _SIENA_PORT_H_
#define _SIENA_PORT_H_

#include <stdint.h>

inline uint8_t
inb(uint16_t p)
{
    uint8_t ret;
    asm volatile ("inb %%dx, %%al":"=a"(ret):"d"(p));
    return ret;
}

inline uint16_t
inw(uint16_t p)
{
    uint16_t ret;
    asm volatile ("inw %%dx, %%ax":"=a"(ret):"d"(p));
    return ret;
}

inline uint32_t
ind(uint16_t p)
{
    uint32_t ret;
    asm volatile ("ind %%dx, %%eax":"=a"(ret):"d"(p));
    return ret;
}

inline uint64_t
inq(uint16_t p)
{
    uint64_t ret;
    asm volatile ("inq %%dx, %%rax":"=a"(ret):"d"(p));
    return ret;
}

inline void
outb(uint16_t p, uint8_t v)
{
    asm volatile ("outb %%al, %%dx"::"d"(p),"a"(v));
}

inline void
outw(uint16_t p, uint16_t v)
{
    asm volatile ("outw %%ax, %%dx"::"d"(p),"a"(v));
}

inline void
outd(uint16_t p, uint32_t v)
{
    asm volatile ("outd %%eax, %%dx"::"d"(p),"a"(v));
}

inline void
outq(uint16_t p, uint64_t v)
{
    asm volatile ("outq %%rax, %%dx"::"d"(p),"a"(v));
}

#endif
