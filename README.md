# Password Strength Checker

**A simple password strength checker written in C.**

## Overview

Password Strength Checker is a beginner-friendly C project that evaluates a password using its length and character composition.

It examines whether the password contains letters, digits, and special characters, then estimates its theoretical strength.

## Features

- Checks password length.
- Detects alphabetic characters.
- Detects numeric characters.
- Detects special characters.
- Estimates the possible character combinations.
- Provides a basic password strength classification.

## Requirements

- GCC compiler
- Linux, Windows, or macOS
- C standard library
- Math library

## Installation

Clone the repository:

```bash
git clone https://github.com/Tirthika/password_strength_cheacker.git
cd password_strength_cheacker
```

## Compilation

Compile the C source using GCC:

```bash
gcc password_strength.c -o password_checker -lm
```

If your C source file has a different name, replace `password_strength.c` with its actual filename.

## Run

```bash
./password_checker
```

## Methodology

The program examines the character types present in the password and uses the possible character pool and password length to estimate the theoretical search space.

**Note:** This is an educational estimation, not a real-world password-cracking benchmark. Actual password security depends on many other factors, including password reuse, common patterns, and the hashing algorithm used by the service.

## Limitations

- Does not check passwords against known breached-password databases.
- Does not estimate the strength of a specific password against every real-world attack.
- The theoretical calculation does not represent actual cracking performance.

## Version

**Current version:** v1.0.0
**Current version:** v1.0.0
**Next planned version:** v1.1.1

## License

This project is open source. A license will be added to clarify reuse and contribution permissions.
