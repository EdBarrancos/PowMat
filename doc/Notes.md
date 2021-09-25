# Questions and decisions I made that I'm not certain or just simple Doubts (->)

## Error Handling

Not sure about the best way to handle errors in a program like this

In the meanwhile I updated the way I handle Errors, but I'm not sure its the best way still

## Interpreter

### Lexer

I'll be classifying ```.``` as a separator, but I don't have a use for it now

For now I won't really support comments

Lexer won't raise any syntax error. I'll leave that for the Parser?

-> Do I have to specify in token / lexer what each Seperator Does?
