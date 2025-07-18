# Professional Library Management System

A comprehensive library management system written in C++ with a console user interface (CUI). This system provides complete functionality for managing books, members, borrowing/returning operations, and generating reports.

## Features

### User Authentication
- Secure login system with password masking
- User registration with role-based access (Admin, Librarian, Member)
- Default admin and librarian accounts

### Book Management
- Add new books with complete details (ID, title, author, ISBN, category, publication year, copies)
- Search books by title, author, or category
- View all books with availability status
- Automatic book ID generation

### Member Management
- Add new members with personal information
- Search members by name, email, or phone
- View all registered members
- Automatic member ID generation

### Borrowing/Returning System
- Borrow books with automatic due date calculation (14 days)
- Return books with overdue fine calculation
- View all borrow records
- Track book availability in real-time

### Reports and Analytics
- Generate comprehensive library statistics
- Track total books, members, borrowed books, and overdue items
- View borrowing history and patterns

### Data Persistence
- File-based data storage for books, members, users, and borrow records
- Automatic data saving and loading
- CSV-like format for easy data management

## System Requirements

- C++ compiler with C++17 support (g++, clang++)
- Linux/Unix environment (uses termios.h for password input)
- Make utility (optional, for easier compilation)

## Installation and Usage

### Using Make (Recommended)
```bash
# Compile the program
make

# Run the program
make install
```

### Manual Compilation
```bash
# Create the executable
g++ -std=c++17 -Wall -Wextra -O2 -o library_management src/library_management.cpp

# Create data directory
mkdir -p data

# Run the program
./library_management
```

## Default Login Credentials

The system comes with pre-configured accounts:

- **Admin Account**
  - Username: `admin`
  - Password: `admin123`

- **Librarian Account**
  - Username: `librarian`
  - Password: `lib123`

## File Structure

```
library_management/
├── src/
│   └── library_management.cpp    # Main source code
├── data/                         # Data files (auto-created)
│   ├── books.txt                # Book records
│   ├── members.txt              # Member records
│   ├── users.txt                # User accounts
│   └── borrow_records.txt       # Borrowing records
├── Makefile                     # Build configuration
└── README.md                    # This file
```

## Usage Guide

### 1. Starting the System
Run the compiled executable to start the library management system. You'll be presented with the main menu.

### 2. Logging In
Use the default credentials or register a new account. The system supports three user roles:
- **Admin**: Full system access
- **Librarian**: Book and member management, borrowing operations
- **Member**: Limited access (future enhancement)

### 3. Managing Books
- Add new books with complete bibliographic information
- Search existing books by various criteria
- View availability status and copy counts

### 4. Managing Members
- Register new library members
- Search and view member information
- Track membership details and status

### 5. Borrowing and Returning
- Process book borrowing with automatic due date setting
- Handle book returns with overdue fine calculation
- View borrowing history and current loans

### 6. Generating Reports
- View comprehensive library statistics
- Track system usage and performance metrics

## Key Features

### Security
- Password input masking for secure authentication
- Role-based access control
- Data validation and error handling

### User Experience
- Clean, intuitive console interface
- Clear menu navigation
- Comprehensive error messages and confirmations

### Data Management
- Automatic data persistence
- Robust file handling with error checking
- Data integrity maintenance

### Scalability
- Modular object-oriented design
- Efficient search algorithms
- Expandable architecture for future enhancements

## Technical Specifications

### Classes and Architecture
- **Book**: Manages book information and availability
- **Member**: Handles member data and status
- **BorrowRecord**: Tracks borrowing transactions
- **User**: Manages system authentication
- **Date**: Utility class for date operations
- **LibraryManagement**: Main system controller

### Data Storage
- Text-based file storage with CSV-like format
- Automatic data loading and saving
- Data directory structure for organization

### Input/Output
- Console-based user interface
- Password masking using termios
- Formatted output for readability

## Future Enhancements

- Database integration (SQLite/MySQL)
- Network connectivity for multi-user access
- Advanced reporting with charts and graphs
- Email notifications for due dates
- Barcode scanning support
- Fine management and payment tracking

## Contributing

This is a complete, production-ready library management system. Feel free to extend it with additional features or adapt it for specific requirements.

## License

This project is provided as-is for educational and practical use. Feel free to modify and distribute according to your needs.