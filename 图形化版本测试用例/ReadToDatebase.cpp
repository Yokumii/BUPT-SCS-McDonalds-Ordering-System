#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include "D:\mysql-8.4.0-winx64\include\mysql.h"


using namespace std;

// 结构定义
struct Food {
    int id;
    string name;
    int make_sec;
    int capacity;
};

struct Pack {
    int id;
    string name;
    vector<string> foods;
};

// 数据库连接信息
const char* host = "localhost";
const char* user = "root";
const char* password = "M1xkkvdw";
const char* database = "byr_mcdonald";

// 函数声明
void parseDicFile(const char* filename, int& N, int& M, vector<Food>& foods, vector<Pack>& packs,int& W1, int& W2);
void insertFoods(MYSQL* conn, const vector<Food>& foods);
void insertPacks(MYSQL* conn, const vector<Pack>& packs);
void insertSettings(MYSQL* conn, int W1, int W2);

int main() {
    int N, M;
    vector<Food> foods;
    vector<Pack> packs;
    int W1, W2;

    const char* filename = "dict.dic";
    parseDicFile(filename, N, M, foods, packs,W1, W2);

    MYSQL* conn = mysql_init(NULL);
    if (conn == NULL) {
        cerr << "Error: mysql_init failed." << endl;
        return 1;
    }

    if (!mysql_real_connect(conn, host, user, password, database, 0, NULL, 0)) {
        cerr << "Error: mysql_real_connect failed." << endl;
        return 1;
    }
    
    const char *truncate_table_sql = "DELETE FROM food2";

    if (mysql_query(conn, truncate_table_sql)) {
    }
    
    const char *truncate_table2_sql = "DELETE FROM pack2";

    if (mysql_query(conn, truncate_table2_sql)) {
    }
    
    const char *truncate_table3_sql = "DELETE FROM setting2";

    if (mysql_query(conn, truncate_table3_sql)) {
    }

    std::cout << "Table your_table has been truncated." << std::endl;

    insertFoods(conn, foods);
    insertPacks(conn, packs);    
    insertSettings(conn, W1, W2);
    mysql_close(conn);

    cout << "Data insertion completed successfully." << endl;

    return 0;
}

void parseDicFile(const char* filename, int& N, int& M, vector<Food>& foods, vector<Pack>& packs,int& W1, int& W2) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error: Unable to open file " << filename << endl;
        exit(1);
    }

    file >> N >> M;

    vector<string> food_names(N);
    for (int i = 0; i < N; ++i)
        file >> food_names[i];

    vector<int> make_secs(N);
    for (int i = 0; i < N; ++i)
        file >> make_secs[i];

    vector<int> capacities(N);
    for (int i = 0; i < N; ++i)
        file >> capacities[i];

    file >> W1 >> W2;

    string line;
    getline(file, line); 
    for (int i = 0; i < M; ++i) {
        getline(file, line);
        istringstream iss(line);
        Pack pack;
        pack.id = i; 
        iss >> pack.name;
        string food_name;
        while (iss >> food_name) {
            pack.foods.push_back(food_name);
        }
        packs.push_back(pack);
    }

    for (int i = 0; i < N; ++i) {
        Food food;
        food.id = i;
        food.name = food_names[i];
        food.make_sec = make_secs[i];
        food.capacity = capacities[i];
        foods.push_back(food);
    }

    file.close();
}

void insertFoods(MYSQL* conn, const vector<Food>& foods) {
    for (const auto& food : foods) {
        ostringstream oss;
        oss << "INSERT INTO food2 (FoodID, FoodName, FoodCap, FoodMakeSec, FoodImage) VALUES (" 
            << food.id << ", '" << food.name << "', " << food.capacity << ", " << food.make_sec 
            << ", './food_icon/" << food.name << ".png')";
        if (mysql_query(conn, oss.str().c_str())) {
            cerr << "Error: Failed to insert food " << food.name << ": " << mysql_error(conn) << endl;
            exit(1);
        }
    }
}

void insertPacks(MYSQL* conn, const vector<Pack>& packs) {
    for (const auto& pack : packs) {
        ostringstream oss;
        oss << "INSERT INTO pack2 (PackID, PackName, PackInclude, PackImage) VALUES (" 
            << pack.id << ", '" << pack.name << "', '";

        oss << "[";
        for (size_t i = 0; i < pack.foods.size(); ++i) {
            oss << "\"" << pack.foods[i] << "\""; 
            if (i < pack.foods.size() - 1)
                oss << ", ";
        }
        oss << "]";

        oss << "', './pack_icon/" << pack.name << ".png')";
        if (mysql_query(conn, oss.str().c_str())) {
            cerr << "Error: Failed to insert pack " << pack.name << ": " << mysql_error(conn) << endl;
            exit(1);
        }
    }
}

void insertSettings(MYSQL* conn, int W1, int W2) {
    ostringstream oss;
    oss << "INSERT INTO setting2 (W_1, W_2) VALUES (" << W1 << ", " << W2 << ")";
    if (mysql_query(conn, oss.str().c_str())) {
        cerr << "Error: Failed to insert settings: " << mysql_error(conn) << endl;
        exit(1);
    }
}









