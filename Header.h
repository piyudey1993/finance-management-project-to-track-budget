#ifndef HEADER_H
#define HEADER_H
#include<iostream>
#include<map>
#include<vector>
#include<unordered_map>
#include <functional>
using namespace std;

class registration{
    std::map<std::string, std::string> user;
    bool status_flag = false;
    string currentUser;
public:
    registration();
    void login();
    bool get_status();
    string get_current_user();
};

struct detail {
    std::string category;
    std::string date;
    int amount;
    static int savingamount;
};

class tracking_strategy {
public:
    virtual void enter_data(string category, int amount, string date) = 0;
    virtual void total_amount() = 0;
    virtual void get_max_amount() = 0;
    virtual void get_min_amount() = 0;
    virtual void show_data() = 0;
    virtual bool check_date(string date) = 0;
    virtual void get_range_date_amount(const std::string& date1, const std::string& date2) = 0;
    virtual void delete_expense(const std::string& category) = 0;
    virtual void show_value_based_on_catagory(string category)=0;
};

class tracking_expense : public tracking_strategy {
    static std::vector<detail> expense_tracker;
public:
    void enter_data(string category, int amount, string date) override;
    void total_amount() override;
    void get_max_amount() override;
    void get_min_amount() override;
    void show_data() override;
    void check_list();
    bool check_date(string date) override;
    void get_range_date_amount(const std::string& date1, const std::string& date2) override;
    void delete_expense(const std::string& category) override;
    void show_value_based_on_catagory(string category) override;
};

class tracking_income : public tracking_strategy {
    static std::vector<detail> income_tracker;
public:
    void enter_data(string category, int amount, string date) override;
    void total_amount() override;
    void get_max_amount() override;
    void get_min_amount() override;
    void show_data() override;
    void check_list();
    bool check_date(string date) override;
    void get_range_date_amount(const std::string& date1, const std::string& date2) override;
    void delete_expense(const std::string& category) override;
    void show_value_based_on_catagory(string category) override;
};

class budget_tracker {
    unique_ptr<tracking_strategy> tracker;
public:
    budget_tracker(unique_ptr<tracking_strategy> track);
    void print_menu();
    void managing_data();
};
#endif // HEADER_H
#pragma once
