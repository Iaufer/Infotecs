#include <iostream>
#include <sqlite3.h>

int main() {
    sqlite3* db;
    char* errorMessage = nullptr;

    int rc = sqlite3_open("mydatabase.db", &db);
    if (rc) {
        std::cerr << "Не удалось открыть/создать базу данных: " << std::endl;
        return rc;
    }
    
    sqlite3_close(db);

    return 0;
}
