# Cadump Language

## Main principles

- every object has stdin, stdout
- every object has child stderr object, except for stderr object
- its parent's responsibility to handle errors
- everything is an object, either nested or not
- every object has array of its children accesible by their name or index
- every object is ambiguous
- unspecified left side of stdin/stdout in an object defaults to parent's stdin/stdout
- all, even nested objects are accessible by their parents
- program ends by number (exit code)

---

## Enviromental objects

### std

object representing input and output stream of the program

## Syntax

### pipelines

`>` use stdout of the right object as stdin of the left object
`<` use stdout of the left object as stdin of the right object

### objects

objects are defined by `name` or by brackets `()`

### children

objects can acces children of children by `.` followed by name of the child

### stdin

objects can get their input whith the `>` with empty left side

### stdout

objects can return their output with the `<` with empty left side

### stderr

objects can access stderr by `stderr`

### exit codes

