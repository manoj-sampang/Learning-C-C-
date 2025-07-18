#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
#include <iomanip>
#include <termios.h>
#include <unistd.h>
#include <ctime>
#include <limits>

using namespace std;

// Utility function for password input
char getch() {
    char buf = 0;
    termios old = {};
    tcgetattr(STDIN_FILENO, &old);
    termios new_t = old;
    new_t.c_lflag &= ~ICANON;
    new_t.c_lflag &= ~ECHO;
    tcsetattr(STDIN_FILENO, TCSANOW, &new_t);
    read(STDIN_FILENO, &buf, 1);
    tcsetattr(STDIN_FILENO, TCSANOW, &old);
    return buf;
}

// Date utility class
class Date {
private:
    string date_str;
    
public:
    Date() {
        time_t now = time(0);
        tm* ltm = localtime(&now);
        date_str = std::to_string(1900 + ltm->tm_year) + "/" + 
                  std::to_string(1 + ltm->tm_mon) + "/" + 
                  std::to_string(ltm->tm_mday);
    }
    
    Date(const string& d) : date_str(d) {}
    
    string get_date() const { return date_str; }
    void set_date(const string& d) { date_str = d; }
    
    bool is_valid() const {
        // Basic date validation
        if (date_str.length() != 10) return false;
        if (date_str[4] != '/' || date_str[7] != '/') return false;
        return true;
    }
};

// Book class
class Book {
private:
    string book_id;
    string title;
    string author;
    string isbn;
    string category;
    int publication_year;
    int total_copies;
    int available_copies;
    
public:
    Book() : publication_year(0), total_copies(0), available_copies(0) {}
    
    Book(const string& id, const string& t, const string& a, const string& i, 
         const string& c, int year, int total, int available)
        : book_id(id), title(t), author(a), isbn(i), category(c), 
          publication_year(year), total_copies(total), available_copies(available) {}
    
    // Getters
    string get_id() const { return book_id; }
    string get_title() const { return title; }
    string get_author() const { return author; }
    string get_isbn() const { return isbn; }
    string get_category() const { return category; }
    int get_publication_year() const { return publication_year; }
    int get_total_copies() const { return total_copies; }
    int get_available_copies() const { return available_copies; }
    
    // Setters
    void set_id(const string& id) { book_id = id; }
    void set_title(const string& t) { title = t; }
    void set_author(const string& a) { author = a; }
    void set_isbn(const string& i) { isbn = i; }
    void set_category(const string& c) { category = c; }
    void set_publication_year(int year) { publication_year = year; }
    void set_total_copies(int total) { total_copies = total; }
    void set_available_copies(int available) { available_copies = available; }
    
    // Methods
    bool is_available() const { return available_copies > 0; }
    void borrow_book() { if (available_copies > 0) available_copies--; }
    void return_book() { if (available_copies < total_copies) available_copies++; }
    
    string to_string() const {
        stringstream ss;
        ss << book_id << "," << title << "," << author << "," << isbn << "," 
           << category << "," << publication_year << "," << total_copies << "," 
           << available_copies;
        return ss.str();
    }
    
    void from_string(const string& str) {
        stringstream ss(str);
        string item;
        
        getline(ss, book_id, ',');
        getline(ss, title, ',');
        getline(ss, author, ',');
        getline(ss, isbn, ',');
        getline(ss, category, ',');
        getline(ss, item, ',');
        publication_year = std::stoi(item);
        getline(ss, item, ',');
        total_copies = std::stoi(item);
        getline(ss, item, ',');
        available_copies = std::stoi(item);
    }
};

// Member class
class Member {
private:
    string member_id;
    string name;
    string email;
    string phone;
    string address;
    string membership_type;
    Date join_date;
    bool is_active;
    
public:
    Member() : is_active(true) {}
    
    Member(const string& id, const string& n, const string& e, const string& p, 
           const string& addr, const string& type)
        : member_id(id), name(n), email(e), phone(p), address(addr), 
          membership_type(type), is_active(true) {}
    
    // Getters
    string get_id() const { return member_id; }
    string get_name() const { return name; }
    string get_email() const { return email; }
    string get_phone() const { return phone; }
    string get_address() const { return address; }
    string get_membership_type() const { return membership_type; }
    string get_join_date() const { return join_date.get_date(); }
    bool get_is_active() const { return is_active; }
    
    // Setters
    void set_id(const string& id) { member_id = id; }
    void set_name(const string& n) { name = n; }
    void set_email(const string& e) { email = e; }
    void set_phone(const string& p) { phone = p; }
    void set_address(const string& addr) { address = addr; }
    void set_membership_type(const string& type) { membership_type = type; }
    void set_is_active(bool active) { is_active = active; }
    
    string to_string() const {
        stringstream ss;
        ss << member_id << "," << name << "," << email << "," << phone << "," 
           << address << "," << membership_type << "," << join_date.get_date() << "," 
           << (is_active ? "1" : "0");
        return ss.str();
    }
    
    void from_string(const string& str) {
        stringstream ss(str);
        string item;
        
        getline(ss, member_id, ',');
        getline(ss, name, ',');
        getline(ss, email, ',');
        getline(ss, phone, ',');
        getline(ss, address, ',');
        getline(ss, membership_type, ',');
        getline(ss, item, ',');
        join_date.set_date(item);
        getline(ss, item, ',');
        is_active = (item == "1");
    }
};

// Borrow Record class
class BorrowRecord {
private:
    string record_id;
    string book_id;
    string member_id;
    Date borrow_date;
    Date due_date;
    Date return_date;
    bool is_returned;
    double fine_amount;
    
public:
    BorrowRecord() : is_returned(false), fine_amount(0.0) {}
    
    BorrowRecord(const string& rid, const string& bid, const string& mid)
        : record_id(rid), book_id(bid), member_id(mid), is_returned(false), fine_amount(0.0) {
        // Set due date to 14 days from now
        time_t now = time(0);
        time_t due_time = now + (14 * 24 * 60 * 60);
        tm* due_tm = localtime(&due_time);
        string due_str = std::to_string(1900 + due_tm->tm_year) + "/" + 
                        std::to_string(1 + due_tm->tm_mon) + "/" + 
                        std::to_string(due_tm->tm_mday);
        due_date.set_date(due_str);
    }
    
    // Getters
    string get_record_id() const { return record_id; }
    string get_book_id() const { return book_id; }
    string get_member_id() const { return member_id; }
    string get_borrow_date() const { return borrow_date.get_date(); }
    string get_due_date() const { return due_date.get_date(); }
    string get_return_date() const { return return_date.get_date(); }
    bool get_is_returned() const { return is_returned; }
    double get_fine_amount() const { return fine_amount; }
    
    // Setters
    void set_record_id(const string& rid) { record_id = rid; }
    void set_book_id(const string& bid) { book_id = bid; }
    void set_member_id(const string& mid) { member_id = mid; }
    void set_fine_amount(double amount) { fine_amount = amount; }
    
    void mark_returned() {
        is_returned = true;
        return_date = Date();
    }
    
    bool is_overdue() const {
        if (is_returned) return false;
        // Simple date comparison (assuming YYYY/MM/DD format)
        Date today;
        return today.get_date() > due_date.get_date();
    }
    
    string to_string() const {
        stringstream ss;
        ss << record_id << "," << book_id << "," << member_id << "," 
           << borrow_date.get_date() << "," << due_date.get_date() << "," 
           << return_date.get_date() << "," << (is_returned ? "1" : "0") << "," 
           << fine_amount;
        return ss.str();
    }
    
    void from_string(const string& str) {
        stringstream ss(str);
        string item;
        
        getline(ss, record_id, ',');
        getline(ss, book_id, ',');
        getline(ss, member_id, ',');
        getline(ss, item, ',');
        borrow_date.set_date(item);
        getline(ss, item, ',');
        due_date.set_date(item);
        getline(ss, item, ',');
        return_date.set_date(item);
        getline(ss, item, ',');
        is_returned = (item == "1");
        getline(ss, item, ',');
        fine_amount = std::stod(item);
    }
};

// User class for authentication
class User {
private:
    string username;
    string password;
    string role; // admin, librarian, member
    string full_name;
    
public:
    User() {}
    
    User(const string& user, const string& pass, const string& r, const string& name)
        : username(user), password(pass), role(r), full_name(name) {}
    
    // Getters
    string get_username() const { return username; }
    string get_password() const { return password; }
    string get_role() const { return role; }
    string get_full_name() const { return full_name; }
    
    // Setters
    void set_username(const string& user) { username = user; }
    void set_password(const string& pass) { password = pass; }
    void set_role(const string& r) { role = r; }
    void set_full_name(const string& name) { full_name = name; }
    
    string to_string() const {
        stringstream ss;
        ss << username << "," << password << "," << role << "," << full_name;
        return ss.str();
    }
    
    void from_string(const string& str) {
        stringstream ss(str);
        getline(ss, username, ',');
        getline(ss, password, ',');
        getline(ss, role, ',');
        getline(ss, full_name, ',');
    }
};

// Main Library Management System class
class LibraryManagement {
private:
    vector<Book> books;
    vector<Member> members;
    vector<BorrowRecord> borrow_records;
    vector<User> users;
    User current_user;
    bool is_logged_in;
    
    // File paths
    const string BOOKS_FILE = "data/books.txt";
    const string MEMBERS_FILE = "data/members.txt";
    const string RECORDS_FILE = "data/borrow_records.txt";
    const string USERS_FILE = "data/users.txt";
    
public:
    LibraryManagement() : is_logged_in(false) {
        // Create data directory if it doesn't exist
        system("mkdir -p data");
        load_data();
        initialize_default_users();
    }
    
    ~LibraryManagement() {
        save_data();
    }
    
    // Data management methods
    void load_data() {
        load_books();
        load_members();
        load_borrow_records();
        load_users();
    }
    
    void save_data() {
        save_books();
        save_members();
        save_borrow_records();
        save_users();
    }
    
    void load_books() {
        ifstream file(BOOKS_FILE);
        if (!file.is_open()) return;
        
        string line;
        while (getline(file, line)) {
            if (!line.empty()) {
                Book book;
                book.from_string(line);
                books.push_back(book);
            }
        }
        file.close();
    }
    
    void save_books() {
        ofstream file(BOOKS_FILE);
        if (!file.is_open()) return;
        
        for (const auto& book : books) {
            file << book.to_string() << "\n";
        }
        file.close();
    }
    
    void load_members() {
        ifstream file(MEMBERS_FILE);
        if (!file.is_open()) return;
        
        string line;
        while (getline(file, line)) {
            if (!line.empty()) {
                Member member;
                member.from_string(line);
                members.push_back(member);
            }
        }
        file.close();
    }
    
    void save_members() {
        ofstream file(MEMBERS_FILE);
        if (!file.is_open()) return;
        
        for (const auto& member : members) {
            file << member.to_string() << "\n";
        }
        file.close();
    }
    
    void load_borrow_records() {
        ifstream file(RECORDS_FILE);
        if (!file.is_open()) return;
        
        string line;
        while (getline(file, line)) {
            if (!line.empty()) {
                BorrowRecord record;
                record.from_string(line);
                borrow_records.push_back(record);
            }
        }
        file.close();
    }
    
    void save_borrow_records() {
        ofstream file(RECORDS_FILE);
        if (!file.is_open()) return;
        
        for (const auto& record : borrow_records) {
            file << record.to_string() << "\n";
        }
        file.close();
    }
    
    void load_users() {
        ifstream file(USERS_FILE);
        if (!file.is_open()) return;
        
        string line;
        while (getline(file, line)) {
            if (!line.empty()) {
                User user;
                user.from_string(line);
                users.push_back(user);
            }
        }
        file.close();
    }
    
    void save_users() {
        ofstream file(USERS_FILE);
        if (!file.is_open()) return;
        
        for (const auto& user : users) {
            file << user.to_string() << "\n";
        }
        file.close();
    }
    
    void initialize_default_users() {
        if (users.empty()) {
            users.push_back(User("admin", "admin123", "admin", "System Administrator"));
            users.push_back(User("librarian", "lib123", "librarian", "Head Librarian"));
            save_users();
        }
    }
    
    // Utility methods
    void clear_screen() {
        system("clear");
    }
    
    void pause() {
        cout << "\nPress Enter to continue...";
        cin.ignore();
        cin.get();
    }
    
    string get_hidden_input() {
        string password;
        char ch;
        
        while ((ch = getch()) != '\n') {
            if (ch == 127 || ch == 8) { // Backspace
                if (!password.empty()) {
                    password.pop_back();
                    cout << "\b \b";
                    cout.flush();
                }
            } else if (ch >= 32 && ch <= 126) { // Printable characters
                password += ch;
                cout << '*';
                cout.flush();
            }
        }
        cout << endl;
        return password;
    }
    
    string generate_id(const string& prefix) {
        static int counter = 1;
        return prefix + std::to_string(counter++);
    }
    
    // Authentication methods
    bool login() {
        clear_screen();
        cout << "===============================================\n";
        cout << "          LIBRARY MANAGEMENT SYSTEM\n";
        cout << "                  LOGIN\n";
        cout << "===============================================\n\n";
        
        string username, password;
        
        cout << "Username: ";
        getline(cin, username);
        cout << "Password: ";
        password = get_hidden_input();
        
        for (const auto& user : users) {
            if (user.get_username() == username && user.get_password() == password) {
                current_user = user;
                is_logged_in = true;
                cout << "\nLogin successful! Welcome, " << user.get_full_name() << "\n";
                pause();
                return true;
            }
        }
        
        cout << "\nInvalid username or password!\n";
        pause();
        return false;
    }
    
    void logout() {
        is_logged_in = false;
        current_user = User();
        cout << "\nLogged out successfully!\n";
        pause();
    }
    
    bool register_user() {
        clear_screen();
        cout << "===============================================\n";
        cout << "          USER REGISTRATION\n";
        cout << "===============================================\n\n";
        
        string username, password, confirm_password, role, full_name;
        
        cout << "Username: ";
        getline(cin, username);
        
        // Check if username already exists
        for (const auto& user : users) {
            if (user.get_username() == username) {
                cout << "\nUsername already exists!\n";
                pause();
                return false;
            }
        }
        
        cout << "Password: ";
        password = get_hidden_input();
        cout << "Confirm Password: ";
        confirm_password = get_hidden_input();
        
        if (password != confirm_password) {
            cout << "\nPasswords do not match!\n";
            pause();
            return false;
        }
        
        cout << "Full Name: ";
        getline(cin, full_name);
        
        cout << "Role (admin/librarian/member): ";
        getline(cin, role);
        
        if (role != "admin" && role != "librarian" && role != "member") {
            cout << "\nInvalid role!\n";
            pause();
            return false;
        }
        
        User new_user(username, password, role, full_name);
        users.push_back(new_user);
        save_users();
        
        cout << "\nUser registered successfully!\n";
        pause();
        return true;
    }
    
    // Book management methods
    void add_book() {
        clear_screen();
        cout << "===============================================\n";
        cout << "               ADD NEW BOOK\n";
        cout << "===============================================\n\n";
        
        string title, author, isbn, category;
        int year, total_copies;
        
        cin.ignore(); // Clear input buffer
        
        cout << "Title: ";
        getline(cin, title);
        cout << "Author: ";
        getline(cin, author);
        cout << "ISBN: ";
        getline(cin, isbn);
        cout << "Category: ";
        getline(cin, category);
        cout << "Publication Year: ";
        cin >> year;
        cout << "Total Copies: ";
        cin >> total_copies;
        
        string book_id = generate_id("BK");
        Book new_book(book_id, title, author, isbn, category, year, total_copies, total_copies);
        books.push_back(new_book);
        save_books();
        
        cout << "\nBook added successfully! Book ID: " << book_id << "\n";
        pause();
    }
    
    void search_books() {
        clear_screen();
        cout << "===============================================\n";
        cout << "               SEARCH BOOKS\n";
        cout << "===============================================\n\n";
        
        string query;
        cin.ignore();
        cout << "Enter search query (title/author/category): ";
        getline(cin, query);
        
        vector<Book> results;
        for (const auto& book : books) {
            if (book.get_title().find(query) != string::npos ||
                book.get_author().find(query) != string::npos ||
                book.get_category().find(query) != string::npos) {
                results.push_back(book);
            }
        }
        
        if (results.empty()) {
            cout << "\nNo books found matching your search.\n";
        } else {
            cout << "\nSearch Results:\n";
            cout << "-----------------------------------------------\n";
            for (const auto& book : results) {
                display_book_info(book);
                cout << "-----------------------------------------------\n";
            }
        }
        
        pause();
    }
    
    void display_all_books() {
        clear_screen();
        cout << "===============================================\n";
        cout << "               ALL BOOKS\n";
        cout << "===============================================\n\n";
        
        if (books.empty()) {
            cout << "No books in the library.\n";
        } else {
            for (const auto& book : books) {
                display_book_info(book);
                cout << "-----------------------------------------------\n";
            }
        }
        
        pause();
    }
    
    void display_book_info(const Book& book) {
        cout << "Book ID: " << book.get_id() << "\n";
        cout << "Title: " << book.get_title() << "\n";
        cout << "Author: " << book.get_author() << "\n";
        cout << "ISBN: " << book.get_isbn() << "\n";
        cout << "Category: " << book.get_category() << "\n";
        cout << "Publication Year: " << book.get_publication_year() << "\n";
        cout << "Total Copies: " << book.get_total_copies() << "\n";
        cout << "Available Copies: " << book.get_available_copies() << "\n";
        cout << "Status: " << (book.is_available() ? "Available" : "Not Available") << "\n";
    }
    
    // Member management methods
    void add_member() {
        clear_screen();
        cout << "===============================================\n";
        cout << "               ADD NEW MEMBER\n";
        cout << "===============================================\n\n";
        
        string name, email, phone, address, membership_type;
        
        cin.ignore();
        cout << "Name: ";
        getline(cin, name);
        cout << "Email: ";
        getline(cin, email);
        cout << "Phone: ";
        getline(cin, phone);
        cout << "Address: ";
        getline(cin, address);
        cout << "Membership Type (student/faculty/public): ";
        getline(cin, membership_type);
        
        string member_id = generate_id("MEM");
        Member new_member(member_id, name, email, phone, address, membership_type);
        members.push_back(new_member);
        save_members();
        
        cout << "\nMember added successfully! Member ID: " << member_id << "\n";
        pause();
    }
    
    void search_members() {
        clear_screen();
        cout << "===============================================\n";
        cout << "               SEARCH MEMBERS\n";
        cout << "===============================================\n\n";
        
        string query;
        cin.ignore();
        cout << "Enter search query (name/email/phone): ";
        getline(cin, query);
        
        vector<Member> results;
        for (const auto& member : members) {
            if (member.get_name().find(query) != string::npos ||
                member.get_email().find(query) != string::npos ||
                member.get_phone().find(query) != string::npos) {
                results.push_back(member);
            }
        }
        
        if (results.empty()) {
            cout << "\nNo members found matching your search.\n";
        } else {
            cout << "\nSearch Results:\n";
            cout << "-----------------------------------------------\n";
            for (const auto& member : results) {
                display_member_info(member);
                cout << "-----------------------------------------------\n";
            }
        }
        
        pause();
    }
    
    void display_all_members() {
        clear_screen();
        cout << "===============================================\n";
        cout << "               ALL MEMBERS\n";
        cout << "===============================================\n\n";
        
        if (members.empty()) {
            cout << "No members registered.\n";
        } else {
            for (const auto& member : members) {
                display_member_info(member);
                cout << "-----------------------------------------------\n";
            }
        }
        
        pause();
    }
    
    void display_member_info(const Member& member) {
        cout << "Member ID: " << member.get_id() << "\n";
        cout << "Name: " << member.get_name() << "\n";
        cout << "Email: " << member.get_email() << "\n";
        cout << "Phone: " << member.get_phone() << "\n";
        cout << "Address: " << member.get_address() << "\n";
        cout << "Membership Type: " << member.get_membership_type() << "\n";
        cout << "Join Date: " << member.get_join_date() << "\n";
        cout << "Status: " << (member.get_is_active() ? "Active" : "Inactive") << "\n";
    }
    
    // Borrow/Return methods
    void borrow_book() {
        clear_screen();
        cout << "===============================================\n";
        cout << "               BORROW BOOK\n";
        cout << "===============================================\n\n";
        
        string book_id, member_id;
        
        cin.ignore();
        cout << "Book ID: ";
        getline(cin, book_id);
        cout << "Member ID: ";
        getline(cin, member_id);
        
        // Find book
        Book* book = nullptr;
        for (auto& b : books) {
            if (b.get_id() == book_id) {
                book = &b;
                break;
            }
        }
        
        if (!book) {
            cout << "\nBook not found!\n";
            pause();
            return;
        }
        
        if (!book->is_available()) {
            cout << "\nBook is not available for borrowing!\n";
            pause();
            return;
        }
        
        // Find member
        Member* member = nullptr;
        for (auto& m : members) {
            if (m.get_id() == member_id) {
                member = &m;
                break;
            }
        }
        
        if (!member) {
            cout << "\nMember not found!\n";
            pause();
            return;
        }
        
        if (!member->get_is_active()) {
            cout << "\nMember is not active!\n";
            pause();
            return;
        }
        
        // Create borrow record
        string record_id = generate_id("BR");
        BorrowRecord record(record_id, book_id, member_id);
        borrow_records.push_back(record);
        
        // Update book availability
        book->borrow_book();
        
        save_data();
        
        cout << "\nBook borrowed successfully!\n";
        cout << "Record ID: " << record_id << "\n";
        cout << "Due Date: " << record.get_due_date() << "\n";
        pause();
    }
    
    void return_book() {
        clear_screen();
        cout << "===============================================\n";
        cout << "               RETURN BOOK\n";
        cout << "===============================================\n\n";
        
        string record_id;
        
        cin.ignore();
        cout << "Borrow Record ID: ";
        getline(cin, record_id);
        
        // Find borrow record
        BorrowRecord* record = nullptr;
        for (auto& r : borrow_records) {
            if (r.get_record_id() == record_id && !r.get_is_returned()) {
                record = &r;
                break;
            }
        }
        
        if (!record) {
            cout << "\nBorrow record not found or book already returned!\n";
            pause();
            return;
        }
        
        // Find book
        Book* book = nullptr;
        for (auto& b : books) {
            if (b.get_id() == record->get_book_id()) {
                book = &b;
                break;
            }
        }
        
        if (!book) {
            cout << "\nBook not found!\n";
            pause();
            return;
        }
        
        // Calculate fine if overdue
        double fine = 0.0;
        if (record->is_overdue()) {
            cout << "\nBook is overdue!\n";
            cout << "Fine amount ($1 per day): ";
            cin >> fine;
            record->set_fine_amount(fine);
        }
        
        // Mark as returned
        record->mark_returned();
        book->return_book();
        
        save_data();
        
        cout << "\nBook returned successfully!\n";
        if (fine > 0) {
            cout << "Fine collected: $" << fine << "\n";
        }
        pause();
    }
    
    void view_borrow_records() {
        clear_screen();
        cout << "===============================================\n";
        cout << "            BORROW RECORDS\n";
        cout << "===============================================\n\n";
        
        if (borrow_records.empty()) {
            cout << "No borrow records found.\n";
        } else {
            for (const auto& record : borrow_records) {
                display_borrow_record(record);
                cout << "-----------------------------------------------\n";
            }
        }
        
        pause();
    }
    
    void display_borrow_record(const BorrowRecord& record) {
        cout << "Record ID: " << record.get_record_id() << "\n";
        cout << "Book ID: " << record.get_book_id() << "\n";
        cout << "Member ID: " << record.get_member_id() << "\n";
        cout << "Borrow Date: " << record.get_borrow_date() << "\n";
        cout << "Due Date: " << record.get_due_date() << "\n";
        cout << "Return Date: " << record.get_return_date() << "\n";
        cout << "Status: " << (record.get_is_returned() ? "Returned" : 
                               (record.is_overdue() ? "Overdue" : "Borrowed")) << "\n";
        if (record.get_fine_amount() > 0) {
            cout << "Fine Amount: $" << record.get_fine_amount() << "\n";
        }
    }
    
    // Reports and statistics
    void generate_reports() {
        clear_screen();
        cout << "===============================================\n";
        cout << "               LIBRARY REPORTS\n";
        cout << "===============================================\n\n";
        
        int total_books = books.size();
        int total_members = members.size();
        int total_borrowed = 0;
        int total_overdue = 0;
        int total_available = 0;
        
        for (const auto& book : books) {
            total_available += book.get_available_copies();
        }
        
        for (const auto& record : borrow_records) {
            if (!record.get_is_returned()) {
                total_borrowed++;
                if (record.is_overdue()) {
                    total_overdue++;
                }
            }
        }
        
        cout << "Total Books: " << total_books << "\n";
        cout << "Total Members: " << total_members << "\n";
        cout << "Books Currently Borrowed: " << total_borrowed << "\n";
        cout << "Books Available: " << total_available << "\n";
        cout << "Overdue Books: " << total_overdue << "\n";
        cout << "Total Borrow Records: " << borrow_records.size() << "\n";
        
        pause();
    }
    
    // Menu systems
    void main_menu() {
        while (true) {
            clear_screen();
            cout << "===============================================\n";
            cout << "          LIBRARY MANAGEMENT SYSTEM\n";
            cout << "===============================================\n\n";
            cout << "1. Login\n";
            cout << "2. Register\n";
            cout << "3. Exit\n\n";
            cout << "Choose an option: ";
            
            int choice;
            cin >> choice;
            
            switch (choice) {
                case 1:
                    if (login()) {
                        dashboard_menu();
                    }
                    break;
                case 2:
                    register_user();
                    break;
                case 3:
                    cout << "\nThank you for using Library Management System!\n";
                    return;
                default:
                    cout << "\nInvalid choice! Please try again.\n";
                    pause();
            }
        }
    }
    
    void dashboard_menu() {
        while (is_logged_in) {
            clear_screen();
            cout << "===============================================\n";
            cout << "            DASHBOARD - " << current_user.get_full_name() << "\n";
            cout << "            Role: " << current_user.get_role() << "\n";
            cout << "===============================================\n\n";
            
            cout << "1. Book Management\n";
            cout << "2. Member Management\n";
            cout << "3. Borrow/Return\n";
            cout << "4. Reports\n";
            cout << "5. Logout\n\n";
            cout << "Choose an option: ";
            
            int choice;
            cin >> choice;
            
            switch (choice) {
                case 1:
                    book_management_menu();
                    break;
                case 2:
                    member_management_menu();
                    break;
                case 3:
                    borrow_return_menu();
                    break;
                case 4:
                    generate_reports();
                    break;
                case 5:
                    logout();
                    return;
                default:
                    cout << "\nInvalid choice! Please try again.\n";
                    pause();
            }
        }
    }
    
    void book_management_menu() {
        while (true) {
            clear_screen();
            cout << "===============================================\n";
            cout << "            BOOK MANAGEMENT\n";
            cout << "===============================================\n\n";
            
            cout << "1. Add New Book\n";
            cout << "2. Search Books\n";
            cout << "3. Display All Books\n";
            cout << "4. Back to Dashboard\n\n";
            cout << "Choose an option: ";
            
            int choice;
            cin >> choice;
            
            switch (choice) {
                case 1:
                    add_book();
                    break;
                case 2:
                    search_books();
                    break;
                case 3:
                    display_all_books();
                    break;
                case 4:
                    return;
                default:
                    cout << "\nInvalid choice! Please try again.\n";
                    pause();
            }
        }
    }
    
    void member_management_menu() {
        while (true) {
            clear_screen();
            cout << "===============================================\n";
            cout << "            MEMBER MANAGEMENT\n";
            cout << "===============================================\n\n";
            
            cout << "1. Add New Member\n";
            cout << "2. Search Members\n";
            cout << "3. Display All Members\n";
            cout << "4. Back to Dashboard\n\n";
            cout << "Choose an option: ";
            
            int choice;
            cin >> choice;
            
            switch (choice) {
                case 1:
                    add_member();
                    break;
                case 2:
                    search_members();
                    break;
                case 3:
                    display_all_members();
                    break;
                case 4:
                    return;
                default:
                    cout << "\nInvalid choice! Please try again.\n";
                    pause();
            }
        }
    }
    
    void borrow_return_menu() {
        while (true) {
            clear_screen();
            cout << "===============================================\n";
            cout << "            BORROW/RETURN MANAGEMENT\n";
            cout << "===============================================\n\n";
            
            cout << "1. Borrow Book\n";
            cout << "2. Return Book\n";
            cout << "3. View Borrow Records\n";
            cout << "4. Back to Dashboard\n\n";
            cout << "Choose an option: ";
            
            int choice;
            cin >> choice;
            
            switch (choice) {
                case 1:
                    borrow_book();
                    break;
                case 2:
                    return_book();
                    break;
                case 3:
                    view_borrow_records();
                    break;
                case 4:
                    return;
                default:
                    cout << "\nInvalid choice! Please try again.\n";
                    pause();
            }
        }
    }
    
    void run() {
        main_menu();
    }
};

int main() {
    LibraryManagement library;
    library.run();
    return 0;
}