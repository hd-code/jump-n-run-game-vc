# Coding Guidelines

In order to develop this project in a productive manner, there is a set of guidelines for developers to follow. This document specifies how source code should be structured and layouted, provides naming conventions and other rules that should be followed.

## LLVM Coding Standards

It is not necessary to reinvent the wheel every time one needs a vehicle. There are many advanced developer teams in the world, that collected excellent Coding Guidelines over the course of many years. So, coming up with a completely new one is redundant and prone to error.

The basic coding standard for this project is the one used by the **LLVM** team. Read their coding standards at:

<https://llvm.org/docs/CodingStandards.html>.

These rules form the basis for this project. The rest of this document gives some customizations, to either add or slightly modify the rules by the LLVM team. Anything that is not covered here, should be implemented as the LLVM standard suggests.

## Code Formatter

A coding standard is only effective, when used by all team members consistently. However, humans are prone to error and people tend to have endless (and pointless) arguments about code formatting and layout. To quit all of that at once and increase convenience while coding, a code formatting tool should be used.

Code Formatters are helper tools, that will format and layout the source code automatically according to predefined styling rules. They do not alter the programm flow or logic, just things like indentation, removing whitespace, aligning declarations and more.

LLVM develops a great formatter called **`clang-format`**. Find out more at: <https://clang.llvm.org/docs/ClangFormat.html>.

Since we use the LLVM Coding Standard, we also use their styling rules for `clang-format`. The configuration for this project is:

`{BasedOnStyle: LLVM, IndentWidth: 4}`

Clang-format can be used as a cli or integrated with IDEs. The latter is strongly recommended. It is possible to configure an IDE to automatically run clang-format on saving a code file. Find out, how to use it with your IDE:

- Visual Studio: <https://marketplace.visualstudio.com/items?itemName=xaver.clang-format>
- Visual Studio Code: <https://code.visualstudio.com/docs/cpp/cpp-ide>

**Always run `clang-format` before checking in changes in source control!**

*Note:* Using a formatter is somewhat challenging for many developers at first. Mainly, developers complain, that the code formatter produces code, that is not "pretty". However, this is a highly subjective matter. In the end, a team is more productive, when a consistent style is used, as all files look similar.

## Naming Conventions

LLVM has a set of naming conventions. However, they are not ideal. There are discussion in the LLVM team to come up with a better scheme. See: <https://llvm.org/docs/Proposals/VariableNames.html>, when you are interested in the discussion.

For this project, please adhere to the following rules:

### Naming Schemes

First, here is an overview over different schemes, that can be used for naming things:

- `PascalCase`: words are directly appended to each other, the first letter of each word is capitalized
- `camelCase`: same as `PascalCase`, but the very first letter of the very first word is lowercase
- `kebab-case`: all words are lowercase and joined together by a dash (`-`)
- `snake_case`: all words are lowercase and joined together by an underscore (`_`)
- `UPPER_CASE`: same as `snake_case`, but all letters of all words are in caps

### File Naming

Directories and files (including data files and asssets) should be named in `kebab-case`.

There usually is one header and one implementation file for each class. Both should be in the same directory. The filename should be the same as the class name.

Header files use the `.hpp` file extension and source code `.cpp`.

It is not necessary to rename files and directories from external sources.

Good:

```
source/
    data/
        textures/
            a-longer-texture-name.png
            block-cracked.png
    intern/
        game/
            startup-phase.hpp
            startup-phase.cpp
```

Bad:

```
source/
    Data/
        texTuRes/
            IShouldNotHaveCapitalLetters.png
            block__cracked.png
    intern/
        Game/
            Startup_phase.hpp
        game/
            startupPhase.cpp
```

### C++ Code

#### Namespaces

The LLVM rule "Use Namespace Qualifiers to Implement Previously Declared Functions" has not to be followed.

Namespaces should be a short single word, all in lowercase. Abbreviations are okay.

Good:

```cpp
namespace game {
class StartupPhase;
}

namespace logic {
class PlayPhase;
}

namespace gfx {
class MetaEntityFacet;
}

namespace testxml {
tinyxml2::XMLError openXMLFile(const char *filepath);
}
```

Bad:

```cpp
namespace Game {
class StartupPhase;
}

namespace logical_unit {
class PlayPhase;
}

namespace GFX {
class MetaEntityFacet;
}

namespace TEST_XML_FILES {
tinyxml2::XMLError openXMLFile(const char *filepath);
}
```

#### Complex data structures (class, struct, typedef)

Follow the LLVM guide and name them all in `PascalCase`.

Choose somewhat short, but descriptive names. Avoid abbreviations. Name them in singular.

Good:

```cpp
class MyClass;
struct UserData;
typedef unsigned int Id;
```

Bad:

```cpp
class iam_not_correct;
struct UD;
typedef unsigned int COUNTER_VALUES;
```

#### Enums

As enums are also complex data structures they are named in `PascalCase`. Enum members are also named in `PascalCase` and their name should be in the singular. Contrary to the LLVM Guide a prefix for enum members should not be used.

Often there are enums, that are complementary to a class. LLVM suggest in these cases, to name the enum the same as the class and append the suffix `Kind`. This rule should be used here as well.

Good:

```cpp
enum class Color {
    Red,
    Green,
    Blue,
};

struct UserKind {
    typedef enum {
        Human,
        Computer,
        Length,
    } Enum;
};

class User;
```

Bad:

```cpp
enum class color {
    red,
    GREEN,
    dark_blue,
    midnightShade,
};

struct USER_TYPES {
    typedef enum {
        UT_Human,
        UT_Computer,
        NUMBER_OF_ENTRIES,
    } Enum;
};

class User;
```

#### Functions and Methods

Same as LLVM. Functions and Methods should be named in `camelCase` and start with a verb like `get`, `set`, `calc`.

Abbreviations are discouraged, but may be used for obvious cases (like `calc` instead of `calculate`).

Good:

```cpp
int calcTotal(int values[], size_t numOfValues);

class User {
    float getPosition();
    float getSize();
};
```

Bad:

```cpp
int Total(int values[], size_t numOfValues);

class User {
    float POSITION();
    float get_size();
};
```

#### Variables and Function Parameters

Here lies the biggest difference to LLVM. It is more convenient to name variables and parameters in `camelCase`. That way, the instance can have the same name as its corresponding class, struct or type (which is in `PascalCase`).

Since variables and parameters have a small and limited scope, it is okay to use abbreviated names. Just make sure, that enough meaning is conveyed.

Good:

```cpp
int calcTotal(int values[], size_t numOfValues) {
    int result = 0;
    for (auto i = 0, ie = numOfValues; i < ie; ++i) {
        result += values[i];
    }
    return result;
}

void sayHelloDefault() {
    User user;
    user.sayHello();
}
```

Bad:

```cpp
int calcTotal(int _values[], size_t NUM_OF_VALUES) {
    int total_result_of_computation = 0;
    for (auto I = 0; I < NUM_OF_VALUES; ++I) {
        total_result_of_computation += _values[I];
    }
    return total_result_of_computation;
}

void sayHelloDefault() {
    User TheUser;
    TheUser.sayHello();
}
```

#### Class and Struct Members

Like variables, members should be named in `camelCase`. Since they have a wider scope, descriptive names should be used.

In order to specify, that a value is indeed a member, append an underscore (`_`) to its name. This is a common practice in many style guides (e.g. Google's). This prevents conflicts between local scoped variables and members.

Good:

```cpp
class User {
    const char *name_;
    float width_;
};

struct Limits {
    float minimum_;
    float maximum_;
    float previousMinimum_;
    float previousMaximum_;
};
```

Bad:

```cpp
class User {
    const char *name;
    float WIDTH;
};

struct Limits {
    float _minimum;
    float m_;
    float Previous_Minimum;
    float PREVIOUS_MAXIMUM;
};
```
