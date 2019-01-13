#!/usr/bin/env ruby

require "optparse"
require "preprocesor"

optparse = OptionParser.new do |opts|
  opts.on("-i", "--input FILE", "Input FILE") do |file|
    options[:inputfile] = file
  end
  opts.on("-o", "--output FILE", "Output FILE") do |file|
    options[:outputfile] = file
  end

  file = File.read [:inputfile]
  file = preprocesor.process_file(file)
end
