# [nameof](https://github.com/bravikov/nameof)

A header only C++ library provides ```nameof()``` macros to obtain the std::string name of a variable, type, or member.

It works like ```nameof()``` in C#.

The expression ```X``` in ```nameof(X)``` should be compilable.

## Usage

First you should to include name_of.h file.

```cpp
    #include "nameof.h"
```

You can get the name of a variable.

```cpp
    int bar;
    std::string name = nameof(bar); // "bar"
```

You can get the name of a function. You should use an ampersand (```&```).

```cpp
    void foo();
    std::string name = nameof(&foo); // "foo"
```

You can get the name of an enum element.

```cpp
    enum Foo {Bar};
    std::string name = nameof(Foo::Bar); // "Bar"
```

You can get the name of a class or a struct.

```cpp
    class Foo {};
    std::string name = nameof(Foo); // "Foo"
```

You can get the name of a method. Do not forget to add an ampersand (```&```).

```cpp
    struct Foo { int bar(); };
    std::string name = nameof(&Foo::bar); // "bar"
```

You can get the name of a class or struct field.

```cpp
    struct Foo { int bar; };
    std::string name = nameof(Foo::bar); // "bar"
```

You can get the name of a field of an object.

```cpp
    struct Foo { int bar; };
    Foo foo;
    std::string name = nameof(foo.bar); // "bar"
```

You can use ```::```, ```->``` and ```.``` operators with any depth of nesting of entities and with namespaces.

```cpp
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
```

nameof() accepts expression which should be compilable. If expression is compilable but not correspond expressions which shown above, the std::ligic_error exception will be thrown.

Good luck!
