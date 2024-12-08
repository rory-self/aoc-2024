#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

namespace {
    using Equation = std::pair<unsigned long, std::vector<unsigned long>>;

    [[nodiscard]] auto read_equations_from_file(const std::string& file_path) -> std::vector<Equation> {
        std::vector<Equation> equations;

        auto file = std::ifstream(file_path);
        for (std::string line; std::getline(file, line);) {
            constexpr auto result_delimiter = ':';
            auto line_stream = std::stringstream(line);
            std::string result;
            std::getline(line_stream, result, result_delimiter);

            std::vector<unsigned long> terms;
            constexpr auto term_delimiter = ' ';
            for (std::string term; std::getline(line_stream, term, term_delimiter);) {
                if (term.empty()) {
                    continue;
                }

                const auto numeric_term = std::stoul(term);
                terms.push_back(numeric_term);
            }

            const auto numeric_result = std::stoul(result);
            equations.emplace_back(numeric_result, terms);
        }

        return equations;
    }
}

auto main() -> int {
    const auto file_path = std::string{"input.txt"};
    const auto equations = read_equations_from_file(file_path);

    unsigned long test_value_sum = 0;

    std::cout << test_value_sum << std::endl;
    return 0;
}