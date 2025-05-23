#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

void print_json_file(const std::string& filename) {
    std::ifstream input_file(filename);
    if (!input_file.is_open()) {
        std::cerr << "Could not open the file: " << filename << std::endl;
        return;
    }

    try {
        json j;
        input_file >> j;
        std::cout << j.dump(4) << std::endl;
    } catch (const json::parse_error& e) {
        std::cerr << "JSON parse error: " << e.what() << std::endl;
    }
}

void check_product_by_number(const std::string& filename, int product_number) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Failed to open file: " << filename << std::endl;
        return;
    }

    try {
        json products;
        file >> products;

        bool found = false;
        for (const auto& product : products) {
            if (product.contains("item_number") && product["item_number"] == product_number) {
                std::cout << "Item found!" << std::endl;
                found = true;
                break;
            }
        }

        if (!found) {
            std::cout << "Item not found. Please pick another product." << std::endl;
        }

    } catch (const json::exception& e) {
        std::cerr << "JSON error: " << e.what() << std::endl;
    }
}

int main() {
    print_json_file("data.json");
    return 0;
}
