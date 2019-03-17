pub mod tokenizer {
    extern crate phf;

    use phf::phf_map;
    
    enum Token {
        INLINECOMMENT,
        MULTILINECOMMENT,
        STRING,
        NUMBER,
        FLOAT,
        WHOLEKEY,
        KEY,
        SEPARATOR,
        APPEND,
        ASSIGNRIGHT,
        FUNCTION,
        OPENBRACKET,
        CLOSEBRACKET,
        ARRAY,
        OPENSQRBRACKET,
        CLOSESQRBRACKET,
        EQUALS,
        GREATEREQUALS,
        SMALLEREQUALS,
        GREATER,
        SMALLER
    }

    static TOKENS : phf::Map<&'static str, Token> = phf_map! {
        r"/\/\/.*/g" => Token::INLINECOMMENT,
        "PLACEHOLDER" => Token::MULTILINECOMMENT,
        "PLACEHOLDER1" => Token::STRING,
        "PLACEHOLDER2" => Token::NUMBER,
        "PLACEHOLDER3" => Token::FLOAT,
        "PLACEHOLDER4" => Token::WHOLEKEY,
        "[a-z][A-Z]" => Token::KEY,
        "," => Token::SEPARATOR,
        ">>" => Token::APPEND,
        ">" => Token::ASSIGNRIGHT,
        "PLACEHOLDER5" => Token::FUNCTION,
        "(" => Token::OPENBRACKET,
        ")" => Token::CLOSEBRACKET,
        "PLACEHOLDER6" => Token::ARRAY,
        "[" => Token::OPENSQRBRACKET,
        "]" => Token::CLOSESQRBRACKET,
        "?=" => Token::EQUALS,
        "?>=" => Token::GREATEREQUALS,
        "?<=" => Token:;SMALLEREQUALS,
        "?>" => Token::GREATER,
        "?<" => Token::SMALLER
    };

   /* const TOKENS : HashMap =  {
        (KA, 's')
    };*/
    
    struct Tokenizer {
    }

    impl Tokenizer {
        fn tokenize(){}
    }
}
