#include <iostream>
#include <sqlite3.h>

int main() {
    sqlite3* db;
    char* errorMessage = nullptr;

    // Открытие или создание базы данных
    int rc = sqlite3_open("mydatabase.db", &db);
    if (rc) {
        std::cerr << "Не удалось открыть/создать базу данных: " << sqlite3_errmsg(db) << std::endl;
        return rc;
    }

    // Создание таблицы (пример)
    const char* createTableSQL = "CREATE TABLE IF NOT EXISTS MyTable (id INTEGER PRIMARY KEY, name TEXT);";
    rc = sqlite3_exec(db, createTableSQL, nullptr, nullptr, &errorMessage);
    if (rc != SQLITE_OK) {
        std::cerr << "Ошибка при создании таблицы: " << errorMessage << std::endl;
        sqlite3_free(errorMessage);
        return rc;
    }

    // Вставка данных в таблицу (пример)
    const char* insertDataSQL = "INSERT INTO MyTable (name) VALUES ('John Doe');";
    rc = sqlite3_exec(db, insertDataSQL, nullptr, nullptr, &errorMessage);
    if (rc != SQLITE_OK) {
        std::cerr << "Ошибка при вставке данных: " << errorMessage << std::endl;
        sqlite3_free(errorMessage);
        return rc;
    }

    // Выполнение запроса на выборку данных (пример)
    const char* selectDataSQL = "SELECT * FROM MyTable;";
    rc = sqlite3_exec(db, selectDataSQL, [](void* data, int argc, char** argv, char** colName) -> int {
        for (int i = 0; i < argc; ++i) {
            std::cout << colName[i] << ": " << (argv[i] ? argv[i] : "NULL") << "\t";
        }
        std::cout << std::endl;
        return 0;
    }, nullptr, &errorMessage);

    if (rc != SQLITE_OK) {
        std::cerr << "Ошибка при выборке данных: " << errorMessage << std::endl;
        sqlite3_free(errorMessage);
        return rc;
    }

    // Закрытие базы данных
    sqlite3_close(db);

    return 0;
}
