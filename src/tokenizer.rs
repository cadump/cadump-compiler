pub mod tokenizer {
    extern crate phf;

    //use std::collections::HashMap;
    use phf::phf_map;

    #[derive(Clone)]
    pub enum Token {
        INLINECOMMENT,
        MULTILINECOMMENT,
        SQSTRING,
        DQSTRING,
        NUMBER,
        FLOAT,
        WHOLEKEY,
        KEY,
        SEPARATOR,
        APPEND,
        ASSIGNRIGHT,
        FUNCTIONBLOCK,
        OPENBRACKET,
        CLOSEBRACKET,
        ARRAYBLOCK,
        OPENSQRBRACKET,
        CLOSESQRBRACKET,
        EQUALS,
        GREATEREQUALS,
        SMALLEREQUALS,
        GREATER,
        SMALLER,
        ADD,
        SUBSTRACT,
        DIVIDE,
        MULTIPLY
    }
    
    
    static TOKENS : phf::Map<&'static str, Token> = phf_map! {
        r"(\/\/).*" => Token::INLINECOMMENT,
        "PLACEHOLDER" => Token::MULTILINECOMMENT,
        r"'(?:(?>[^'\\]+)|\\.)*'" => Token::SQSTRING,
        r#"(?:(?>[^"\\]+)|\\.)*"# => Token::DQSTRING,
        "[0-9]" => Token::NUMBER,
        "PLACEHOLDER3" => Token::FLOAT,
        "PLACEHOLDER4" => Token::WHOLEKEY,
        "[a-zA-Z]" => Token::KEY,
        "," => Token::SEPARATOR,
        ">>" => Token::APPEND,
        ">" => Token::ASSIGNRIGHT,
        "PLACEHOLDER5" => Token::FUNCTIONBLOCK,
        "(" => Token::OPENBRACKET,
        ")" => Token::CLOSEBRACKET,
        "PLACEHOLDER6" => Token::ARRAYBLOCK,
        "" => Token::OPENSQRBRACKET,
        "]" => Token::CLOSESQRBRACKET,
        "?=" => Token::EQUALS,
        "?>=" => Token::GREATEREQUALS,
        "?<=" => Token::SMALLEREQUALS,
        "?>" => Token::GREATER,
        "?<" => Token::SMALLER,
    };

    
    
    struct Tokenizer {
    }

    impl Tokenizer{
        fn tokenize(){
            let strisa = "\"";
        }
    }
}
