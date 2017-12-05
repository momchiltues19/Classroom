class RomeConverter
	def roman_mapping
		{
			1000 => "M",
			900 => "CM",
			500	=> "D",
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

public

	def self.to_dec(s)
		result = 0
		sth = RomeConverter.new
		str = s
		sth.roman_mapping.values.each do |roman|
			while str.start_with?(roman)
				result += sth.roman_mapping.invert[roman]
				str = str.slice(roman.length, str.length)
			end
		end
		result
	end
	def self.to_rome(r)
		result = ""
		sth = RomeConverter.new
		number = r
		sth.roman_mapping.keys.each do |divisor|
			quotient, modulus = number.divmod(divisor)
			result << sth.roman_mapping[divisor] * quotient
			number = modulus
		end
		result
	end
end
