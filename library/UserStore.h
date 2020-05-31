#pragma once
#include <vector>
#include "User.h"
#include "UserCSVWriter.h"
#include "UserCSVReader.h"

/**
 * @brief Represents an abstract User storage\n 
 * Provides methods for CRUD operations as well as persist and load
 * 
 */
class UserStore
{
private:
    UserCSVReader* reader;
    UserCSVWriter* writer;

    std::vector<User*> users;
public:
    /**
     * @brief Construct a new UserStore object with reader and writer
     * 
     * @param reader the storage reader
     * @param writer the storage writer
     */
    UserStore(UserCSVReader& reader, UserCSVWriter& writer);
    /**
     * @brief Construct a new UserStore object from other
     * 
     * @param other 
     */
    UserStore(const UserStore& other);
    /**
     * @brief Destroy the UserStore object
     * 
     */
    ~UserStore();
    /**
     * @brief Assign UserStore object
     * 
     * @param other 
     * @return UserStore& 
     */
    UserStore& operator = (const UserStore& other);
    /**
     * @brief Swaps the internal data of two UserStore
     * 
     * @param a the first object
     * @param b the second object
     */
    void swap(UserStore& a, UserStore& b);

    /**
     * @brief adds a copy of User to the store
     * 
     * @param user 
     * @return true if the operation completed successfully
     * @return false otherwise
     */
    bool add(const User& user);
    /**
     * @brief Get a User by its username
     * 
     * @param username the username
     * @return User* nullptr if not found
     */
    User* getByUsername(const std::string& username);
    /**
     * @brief Removes a User by its username
     * 
     * @param username 
     * @return true if the operation completed successfully
     * @return false 
     */
    bool removeByUsername(const std::string& username);


    /**
     * @brief Replace the in-memory UserStore from file
     * 
     * @param fileName 
     * @return true if the operation was succesful
     * @return false otherwise
     */
    bool load(const std::string& fileName);
    /**
     * @brief Saves the in-memory UserStore to a file
     * 
     * @param fileName 
     * @return true if the operation was succesful
     * @return false otherwise
     */
    bool save(const std::string& fileName);
};
