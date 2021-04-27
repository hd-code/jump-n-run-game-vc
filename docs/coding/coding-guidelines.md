# Coding Guidelines

In order to develop this project in a productive manner, there is a set of guidelines for developers to follow. This should ensure a uniform structure and layout of the source code. This helps different people to easily interact with the project.

## LLVM Coding Standards

There are many Coding Guidelines out there already. So coming up with a complete new ones is redundant and prone to error. Therefore, ...

https://llvm.org/docs/CodingStandards.html

This guide is the basis for this coding standard. So follow the rules outlined there. However, there are some special cases and deviations for this particular project. These are covered in the rest of this document.

## Tooling

### Why use it

A coding guide is great, but it only works well if it is followed by all people involved. At the same time it imposes a strict and somewhat inconvenient rule set on developers. The ease that burden, there are powerful tools for checking and fixing e.g. code formatting automatically on save. By using such tools, developers can write code more easily and the formatting tool takes care of many (but not all) styling issues.

### Installation & Configuration

LLVM
clang format => LLVM, indent: 4

## Naming Conventions

### General

### Naming Schemes

- camelCase
- PascalCase
- kebab-case
- UPPER_CASE
- snake_case

### Files

Header files use `*.hpp` and implementation `*.cpp`

### Code

Like LLVM: All Types (class, struct) in PascalCase

Enums: PascalCase, Like Types, typical Suffix "Kind" e.g. ValueKind

Functions and Methods: camelCase, start with verb (LLVM)

Variables, parameters: camelCase not like LLVM => similar name to type

Members: members of classes or structs have suffix: _ (Google Coding Guidelines) => clear but uninstrusive way to show scope