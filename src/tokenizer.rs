pub mod tokenizer {
    extern crate phf;

    use phf::phf_map;
    
    enum Token {
        INLINECOMMENT,
        MULTILINECOMMENT,
        STRING,
        TEXT,
        NUMBER,
        FLOAT,
        SEPARATOR,
        ASSIGNRIGHT,
        APPEND,
        OPENBRACKET,
        CLOSEBRACKET,
        OPENSQRBRACKET,
        CLOSESQRBRACKET,
        TREEIDENTIFIER, //the dot for family tree identification
        EQUALS,
        GREATER,
        SMALLER,
        GREATEREQUALS,
        SMALLEREQUALS
    }

    static TOKENS : phf::Map<&'static str, Token> = phf_map! {
        "//" => Token::INLINECOMMENT,
        "PLACEHOLDER" => Token::MULTILINECOMMENT,
        "PLACEHOLDER" => Token::STRING,
                    
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
