pub mod importer {
    use std::fs::File;
    use std::io::prelude::*;
    use std::io::{BufReader};
    use tempfile::tempfile;
    
    struct Import<'a> {
        master_file: &'a File,
        input_file: File,
        //Data about the import
        pub import_level: u32,
        pub import_name: &'a str
    }


    impl<'a> Import <'a> {
        pub fn import(&self, filename:&str, import_level:u32, import_name:&str, import_list:&Vec<Import>) -> &File {
            self.input_file = match File::open(filename) { Ok(file) => file };

            self.master_file = match tempfile() { Ok(file) => &file };
            
            return &self.master_file;            
        }

        fn read(&self) {
            let input_file_bufreader = BufReader::new(self.input_file);
            
            for line in input_file_bufreader.lines() {
                
            }
        }

        fn get_whole_import_command(&self, import_keyword_line:String) {
            
        }

        fn parse_imports(&self, import_command:String) {
            
        }

        fn satisfy_import_scope() {
            
        }

        fn spawn_if_doesnt_exist() {
        }

        fn merge_filestreams() -> String {
            return "ds".to_string();
        }
    }
}
