#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>
#include <ctime>

using json = nlohmann::json;

// Load products from JSON file
json load_products(const std::string& filename) {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Cannot open file: " << filename << std::endl;
        return {};
    }

    json products;
    file >> products;
    return products;
}

// Check if a date string (YYYY-MM-DD) is expired
bool is_expired(const std::string& date_str) {
    std::tm tm = {};
    strptime(date_str.c_str(), "%Y-%m-%d", &tm);
    std::time_t expiry_time = std::mktime(&tm);
    return std::time(nullptr) > expiry_time;
}

// Display available products
void display_products(const json& products) {
    std::cout << "\nAvailable Products:\n";
    for (const auto& item : products) {
        if (item["item_amount"] > 0 && !is_expired(item["item_expiry_date"])) {
            std::cout << "Item Number: " << item["item_number"] << " | "
                      << item["item_name"] << " | $"
                      << item["item_price"] << " | Stock: "
                      << item["item_amount"] << "\n";
        }
    }
}

// Process a purchase
void buy_product(json& products, int number) {
    for (auto& item : products) {
        if (item["item_number"] == number) {
            if (item["item_amount"] == 0) {
                std::cout << "Sorry, that item is out of stock.\n";
                return;
            }
            if (is_expired(item["item_expiry_date"])) {
                std::cout << "Sorry, that item is expired.\n";
                return;
            }

            std::cout << "Item found: " << item["item_name"] << " - $" << item["item_price"] << "\n";
            std::cout << "Dispensing item...\n";
            item["item_amount"] = static_cast<int>(item["item_amount"]) - 1;
            return;
        }
    }

    std::cout << "Item not found. Please try another number.\n";
}

int main() {
    json products = load_products("products.json");
    if (products.empty()) return 1;

    int choice;
    do {
        std::cout << "\n===== Vending Machine =====\n";
        display_products(products);
        std::cout << "\nEnter item number to purchase (0 to exit): ";
        std::cin >> choice;

        if (choice != 0) {
            buy_product(products, choice);
        }

    } while (choice != 0);

    std::cout << "Thank you for using the vending machine!\n";
    return 0;
}
