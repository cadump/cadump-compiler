use std::env;

extern crate tempfile;

mod importer;
mod tokenizer;

fn main() {
    let args: Vec<_> = env::args().collect();
    if args.len() > 1 {
        //TODO the magic
    }

    let importer =  Importer;
}
