#ifndef USER_H
#define USER_H
#include <QString>
class User{
protected:
    QString username;
    QString password;
    QString email;
public:
    User(const QString& uName, const QString& pass, const QString& mail)
        : username(uName), password(pass), email(mail) {}

    // Virtual methods to be overridden by derived classes
    virtual bool login(const QString& enteredUsername, const QString& enteredPassword) = 0;
    virtual void viewProfile() {
    }

    // Getter methods
    QString getUsername() const { return username; }
    QString getPassword() const { return password; }
    QString getEmail() const { return email; }

};

#endif // USER_H
