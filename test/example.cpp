/****************************************************************************
**
** MIT License
**
** Copyright (c) 2018 Dmitry Bravikov
**
** Permission is hereby granted, free of charge, to any person obtaining a
** copy of this software and associated documentation files (the "Software"),
** to deal in the Software without restriction, including without limitation
** the rights to use, copy, modify, merge, publish, distribute, sublicense,
** and/or sell copies of the Software, and to permit persons to whom the
** Software is furnished to do so, subject to the following conditions:
**
** The above copyright notice and this permission notice shall be included
** in all copies or substantial portions of the Software.
**
** THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
** OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
** FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
** THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
** LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
** FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
** DEALINGS IN THE SOFTWARE.
**
****************************************************************************/

/* Project site: https://github.com/bravikov/nameof */

#include <iostream>

#include "../nameof.h"

void example_for_readme();

int main()
{
    example_for_readme();
    return 0;
}

void example_for_readme()
{
    {
        int bar;
        std::string name = nameof(bar); // "bar"
        std::cout << name << std::endl;
    }

    {
        void foo();
        std::string name = nameof(&foo); // "foo"
        std::cout << name << std::endl;
    }

    {
        enum Foo {Bar};
        std::string name = nameof(Foo::Bar); // "Bar"
        std::cout << name << std::endl;
    }

    {
        class Foo {};
        std::string name = nameof(Foo); // "Foo"
        std::cout << name << std::endl;
    }

    {
        struct Foo { int bar(); };
        std::string name = nameof(&Foo::bar); // "bar"
        std::cout << name << std::endl;
    }

    {
        struct Foo { int bar; };
        std::string name = nameof(Foo::bar); // "bar"
        std::cout << name << std::endl;
    }

    {
        struct Foo { int bar; };
        Foo foo;
        std::string name = nameof(foo.bar); // "bar"
        std::cout << name << std::endl;
    }

    {
        struct Foo1
        {
            struct Foo2
            {
                Foo1* foo1;
            };

            Foo1* foo1;
            Foo2 foo2;
        };
        std::string name = nameof(Foo1::foo1->foo2.foo1); // "foo1"
        std::cout << name << std::endl;
    }
}
