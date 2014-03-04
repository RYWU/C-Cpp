
## => .rb
##   Created by WILLIAM on 3/1/14.
##   Copyright (c) 2014 吳瑞洋公司. All rights reserved.
##


print "Yang shen shi hou zhe.";
word = gets.chomp;
puts "The word is #{word}";

print "input:";
user_input = gets.chomp;
if user_input.include? "s";
    user_input.gsub!(/s/, "th");
else
    print "No";
end

puts user_input.downcase!;

