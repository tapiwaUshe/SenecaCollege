/*********************************************************************************
 *  WEB322 – Assignment 06
 *  I declare that this assignment is my own work in accordance with Seneca  Academic Policy.
 *  No part *  of this assignment has been copied manually or electronically from any other source
 *  (including 3rd party web sites) or distributed to other students.
 *
 *  Name: Tapiwa Z. Ushe Student ID: 045787132 Date: Nov 20, 2019
 *
 * Online(Heroku) Link: https: //serene-shore-02740.herokuapp.com/ | https://git.heroku.com/serene-shore-02740.git
 *
 ********************************************************************************/

const mongoose = require("mongoose");
const Schema = mongoose.Schema;
const bcrypt = require('bcryptjs');
var userSchema = new Schema({
    "userName": {
        "type": String,
        "unique": true
    },
    "password": String,

    "loginHistory": [{
        "dateTime": Date,
        "userAgent": String
    }]
});

let User;
module.exports.initialize = function () {
    return new Promise(function (resolve, reject) {
        let db = mongoose.createConnection("mongodb+srv://dbUser:MBWYQscNAX2XWY2u@cluster0-cj8ok.mongodb.net/web322_a6?retryWrites=true");
        db.on('error', (err) => { reject(err); });
        db.once('open', () => {
            User = db.model("Users", userSchema);
            resolve();
        });
    });
};

module.exports.registerUser = function (userData) {
    return new Promise(function (resolve, reject) {
        if (userData.password != userData.password2) reject("Passwords do not match");
        else{
            var newUser = new User(userData);
            bcrypt.genSalt(10, function (err, salt) {
                bcrypt.hash(userData.password, salt, function (err, hash) {
                    if (err) reject("There was an error encrypting the password");
                    else {
                        newUser.password = hash;
                        newUser.save()
                            .then(() => { resolve(); })
                            .catch((err) => {
                                if (err.code == 11000)  reject("User Name already taken");
                                else reject("There was an error creating the user: err" + err);
                            });
                    }
                });
            });
        }
    });
};

module.exports.checkUser = (userData)=> {
    return new Promise((resolve, reject)=> {
        User.find({userName: userData.userName })
          .exec()
          .then((locateUsr) => {
                bcrypt.compare(userData.password, locateUsr[0].password)
                    .then((res) => {
                        locateUsr[0].loginHistory.push({
                            dateTime: (new Date()).toString(),
                            userAgent: userData.userAgent
                        });
                        User.update({ userName: locateUsr[0].userName },
                          { $set: { loginHistory: locateUsr[0].loginHistory } },
                          { multi: false })
                          .exec().then(() => { resolve(locateUsr[0]); })
                          .catch((err) => { reject("There was an error verifying the user: " + err); });
                        })
                        .catch((err) => { reject("Incorrect Password for user: " + userData.userName); })
            })
            .catch((err) => { reject("Unable to find user: " + userData.userName); });
    });
};
