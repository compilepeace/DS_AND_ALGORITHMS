
targets= 06_sqrt 05_pyramid_pattern 04_min_max 03_climits 02_binary_to_decimal 01_pattern 00_sum_of_digits
opt= -Wall -std=c++11

all: $(targets)

01_pattern: 01_pattern.cpp
	g++ $(opt) $< -o $@

00_sum_of_digits: 00_sum_of_digits.cpp
	g++ $(opt) $< -o $@

02_binary_to_decimal: 02_binary_to_decimal.cpp
	g++ $(opt) $< -o $@

03_climits: 03_climits.cpp
	g++ $(opt) $< -o $@

04_min_max: 04_min_max.cpp
	g++ $(opt) $< -o $@

05_pyramid_pattern: 05_pyramid_pattern.cpp
	g++ $(opt) $< -o $@

06_sqrt: 06_sqrt.cpp
	g++ $(opt) $< -o $@

clean:
	rm $(targets)
