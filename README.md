# safetext
Provide a base64 safe encoding or arbitary inputs with a codebook style cipher

Provided an abitrary input data, safetext will encode it into a
base64-like stre am that can be later decoded.

This repository provides some basic tools that demonstrate the use of
the librar ies here.

To get started, clone this repository and run make in the root
director.

It will produce some tools (in the source directory).

You can then experiment with the utilities safeencode, and safedecode
provided t here.

For example, repeatedly running 'safeencode' on a string shows that
the encoded value is different each time.

```
amrith@amrith-work:~/source/safetext/source$ ./safeencode 'the time has come the walrus said to speak of many things'
qXgorSoIJOGdftILgo46jOqwfOy+go46JOGdftJGgtN0C-KwFod9ftI+ftyXvoqWfO5sfO0Ggx96JOGLgsJw
amrith@amrith-work:~/source/safetext/source$ ./safeencode 'the time has come the walrus said to speak of many things'
nXZFi9Z3KP4TY2Amp-z0bPJ6YP5ep-z0KP4TY2K4p2SlfaM6L-TuY2AeY25Cj-JNYPitYPl4p7u0KP4mptK6
amrith@amrith-work:~/source/safetext/source$ ./safeencode 'the time has come the walrus said to speak of many things'
DMSCD9tREvrOif1qomb5DvQcivYuomb5EvrOifErofB7pVTc6mOMif1uifYdAmQSivwKiv7ro9M5EvrqoKEc
amrith@amrith-work:~/source/safetext/source$
```

However, decode any of those, and you'll get the input string.

```
aamrith@amrith-work:~/source/safetext/source$ ./safedecode qXgorSoIJOGdftILgo46jOqwfOy+go46JOGdftJGgtN0C-KwFod9ftI+ftyXvoqWfO5sfO0Ggx96JOGLgsJw
the time has come the walrus said to speak of many things
amrith@amrith-work:~/source/safetext/source$ ./safedecode nXZFi9Z3KP4TY2Amp-z0bPJ6YP5ep-z0KP4TY2K4p2SlfaM6L-TuY2AeY25Cj-JNYPitYPl4p7u0KP4mptK6
the time has come the walrus said to speak of many things
amrith@amrith-work:~/source/safetext/source$ ./safedecode DMSCD9tREvrOif1qomb5DvQcivYuomb5EvrOifErofB7pVTc6mOMif1uifYdAmQSivwKiv7ro9M5EvrqoKEc
the time has come the walrus said to speak of many things
```

## Building

Simply run `make` in the root of the repository. It will perform a
sub-make in the source directory, and this produces a codebook. Note
that the codebook (codebook.c) is not in the repository.

## Making changes

Once you make changes, re-run the make target called tests. It will
exercise both the base64 codec and the safe codec.