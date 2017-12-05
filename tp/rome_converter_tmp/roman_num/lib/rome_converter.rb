class RomeConverter
public

	def self.to_rome (int_arg)
		result = ""
		help = RomeConverter.new
		help.roman_mapping.keys.each do |divisor|
			quotient, modulus = int_arg.divmod(divisor)
			result << help.roman_mapping[divisor] * quotient
			int_arg = modulus
		end
		result
	end

	def self.to_dec (string_arg)
		result = 0
		help = RomeConverter.new
		help.roman_mapping.keys.each do|roman|
			while string_arg.start_with?(roman)
				result += help.roman_mapping.invert[roman]
				string_arg = string_arg.slice(roman.length, string_arg.length)
			end
		end
		result
	end

	def roman_mapping
		{
			1000 => "M",
			900 => "CM",
			500 => "D",
			400 => "CD",
			100 => "C",
			90 => "XC",
			50 => "L",
			40 => "XL",
			10 => "X",
			9 => "IX",
			5 => "V",
			4 => "IV",
			1 => "I"
		}
	end
end

