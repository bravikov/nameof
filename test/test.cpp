/****************************************************************************
** Test of nameof() Macros
** https://github.com/bravikov/nameof
**
** MIT License
**
** Copyright (c) 2018 Dmitry Bravikov <dmitry@bravikov.pro>
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

#include "../nameof.h"

#define BOOST_TEST_MODULE nameof
#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(variable) {
    int bar;
    std::string name = nameof(bar);
    BOOST_REQUIRE_EQUAL(name, "bar");

    int Bar;
    name = nameof(Bar);
    BOOST_REQUIRE_EQUAL(name, "Bar");

    int _bar1;
    name = nameof(_bar1);
    BOOST_REQUIRE_EQUAL(name, "_bar1");

    int _;
    name = nameof(_);
    BOOST_REQUIRE_EQUAL(name, "_");

    int _1;
    name = nameof(_1);
    BOOST_REQUIRE_EQUAL(name, "_1");
}

BOOST_AUTO_TEST_CASE(function) {
    void foo();
    std::string name = nameof(&foo);
    BOOST_REQUIRE_EQUAL(name, "foo");

    void _foo();
    name = nameof(&_foo);
    BOOST_REQUIRE_EQUAL(name, "_foo");

    void _foo1();
    name = nameof(&_foo1);
    BOOST_REQUIRE_EQUAL(name, "_foo1");
    
    void _();
    name = nameof(&_);
    BOOST_REQUIRE_EQUAL(name, "_");
}

BOOST_AUTO_TEST_CASE(enumElement) {
    enum Foo {Bar};
    std::string name = nameof(Foo::Bar);
    BOOST_REQUIRE_EQUAL(name, "Bar");

    enum _Foo1 {_Bar1};
    name = nameof(_Foo1::_Bar1);
    BOOST_REQUIRE_EQUAL(name, "_Bar1");
}

BOOST_AUTO_TEST_CASE(class_) {
    class Foo {};
    std::string name = nameof(Foo);
    BOOST_REQUIRE_EQUAL(name, "Foo");
}

BOOST_AUTO_TEST_CASE(method) {
    struct Foo { int bar(); };
    std::string name = nameof(&Foo::bar);
    BOOST_REQUIRE_EQUAL(name, "bar");
}

BOOST_AUTO_TEST_CASE(classField) {
    struct Foo { int bar; };
    std::string name = nameof(Foo::bar);
    BOOST_REQUIRE_EQUAL(name, "bar");
}

BOOST_AUTO_TEST_CASE(objectField) {
    struct Foo { int bar; };
    Foo foo;
    std::string name = nameof(foo.bar);
    BOOST_REQUIRE_EQUAL(name, "bar");
}

BOOST_AUTO_TEST_CASE(nesting) {
    struct Foo1
    {
        struct Foo2
        {
            Foo1* foo1;
        };

        Foo1* foo1;
        Foo2 foo2;
    };
    std::string name = nameof(Foo1::foo1->foo2.foo1);
    BOOST_REQUIRE_EQUAL(name, "foo1");
}

BOOST_AUTO_TEST_CASE(exceptions) {
    BOOST_REQUIRE_THROW(nameof(123), std::logic_error);
    BOOST_REQUIRE_THROW(nameof("123"), std::logic_error);
    BOOST_REQUIRE_THROW(nameof('1'), std::logic_error);

    int foo1();
    BOOST_REQUIRE_THROW(nameof(foo1()), std::logic_error);

    int* foo2;
    BOOST_REQUIRE_THROW(nameof(*foo2), std::logic_error);
    BOOST_REQUIRE_THROW(nameof(foo2 + 1), std::logic_error);
}
