class prepocessor

    def split_by_linebreaks(file)
        file = file.split("\n")
    end

    def remove_inline_comments(file)
        file.each do |line|
            line = /.+?(?=\/\/)/.match(line)
        end
        return file
    end

    def process_file(file)
        file = @remove_inline_comments(@split_by_linebreaks(file))

        return file
    end
end