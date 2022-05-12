# Public-repository-for-individual-project
This is my final project repository

Background
Base64 is a type of encoding that is quite common in use, especially when working with binary data, transfering it, or accessing data of a browser. This type of encoding is called Base64 as it uses 64 characters in order to output encoded data by using the uppercase and lowercase letters, numbers and '+' with '/'. For example when using base64 encoding one doesn't have to worry about what characters their client's browser can accept, as encoding of base64 transfers all the characters. Or another example is that one has a web service that accepts ASCII characters only, but the user's data should be saved and transferred to other location in a way that the user gets their data untouched. Base64 is also helpful here.

Assumptions and constraints
In order to get to the goal of getting a grade for the individual project, it should be fully done and submitted by the 5/15/2022. Milestones weren't put initially, however a few commits of the uncomplete code are also present in the private repository.

Overview and description of the Envisioned system
Generally speaking, the base64 encoding is going to work in a way that it takes the user input, converts each character to its ASCII value, takes the ASCII values as 8 bit numbers and then makes new 'characters': which are numbers of length of 6 bits, converts those to their base 64 values and if in the bitwise process there is some space that isn't divisible by 6, then 0s are added untill its length is divisble by 6 and replaced with '=' in our code.
The code is in fact quite simple, consisting of a few functions which do the operations described above, in more detail of course, and a better, lower level explanation of each step, written as comments in the code itself. It's a basic C code which shouldn't be more than 200 lines and it takes the input, shows it, so that the user is sure about what the input was, then encodes and prints out the base64 encoded string.
The code should work in any operating system that has a C environment.

Proposed capabilities
The capabilities of the encoding are set to be maximum 500 characters of input, the size can be bigger, much bigger, given even dinamically, but it is given so in order to not occupy much memory as base 64 is usually used for a few lines of text encoding only, in examples like the ones brought above. 

Support environment
As this is a code, then the physical environment isn't much of an issue, and in order to do extra upgrades, one may simply copy the code and do any modifications needed in the code itself, or work with the original if needed. Upgrades may include making the code be able to read from files, but it wasn't done as it's not the main focus of the code.

Operational scenarios
In nominal conditions the code should take the user input and encode it by using base64 encoding.
In off nominal conditions it may not work, but all possible cases were tried and the code should work anyway.

Impact
The impact of the base64 encoder should be easy encoding of binary data via C.

Risks and potential issues
An issue may be, as already mentioned, the limited input size, but it's given to be more than optimal, with extra space consideration too, and even if a very long text should be encoded, then the string size, which is defined in the beginning of the code as SIZE, may simply be changed in the function to any number needed as long as there is enough memory on the device. 

Acronims
ASCII - American Standard Code for Information Interchange

Glossary of terms
Encoding - the process of putting a sequence of characters into a specialized format for efficient transmission or storage
