const Sequelize = require('sequelize');
var sequelize = new Sequelize('database', 'user', 'password', {
    host: 'host',
    dialect: 'postgres',
    port: 5432,
    dialectOptions: { ssl: true }
});

// Define a "Project" model (http://docs.sequelizejs.com/variable/index.html#static-variable-DataTypes)

var Employee = sequelize.define('Employee', {
    employeeNum: {
        type: Sequelize.INTEGER,
        primaryKey: true, // use "employeeNum" as a primary key
        autoIncrement: true // automatically increment the value
    },
    firstName: Sequelize.STRING,
    lastName: Sequelize.STRING,
    email: Sequelize.STRING,
    SSN: Sequelize.STRING,
    addressStreet: Sequelize.STRING,
    addressCity: Sequelize.STRING,
    addressState: Sequelize.STRING,
    addressPostal: Sequelize.STRING,
    maritalStatus: Sequelize.STRING,
    isManager: Sequelize.BOOLEAN,
    employeeManagerNum: Sequelize.INTEGER,
    status: Sequelize.STRING,
    department: Sequelize.INTEGER,
    hireDate: Sequelize.STRING
});

// Define a "Department" model

var Department = sequelize.define('Department', {
    departmentId: {
        type: Sequelize.INTEGER,
        primaryKey: true, // use "departmentId" as a primary key
        autoIncrement: true // automatically increment the value
    },
    departmentName: Sequelize.STRING
});

module.exports.initialize = ()=> {
    return new Promise((resolve, reject)==> {
        sequelize.sync().then( () => { resolve(); })
        .catch(()=>{ reject("unable to sync the database"); });
    });
}

module.exports.getAllEmployees = ()=> {
    return new Promise((resolve, reject)=> {
        Employee.findAll().then((data)=> { resolve(data); })
        .catch((err) => { reject("query returned 0 results"); });
    });
}

module.exports.addEmployee = (employeeData)=> {
    return new Promise((resolve, reject)=> {
        // ternary check, is the empData.isManager value true/false?
        employeeData.isManager = (employeeData.isManager) ? true : false;
        // cycle through empData, if empty string, that value is null.
        for (var prop in employeeData) if(employeeData[prop] == '') employeeData[prop] = null;

        Employee.create(employeeData).then(() => { resolve(); })
        .catch((err)=>{ console.log(err); reject("unable to create employee"); });
    });

};

module.exports.getEmployeeByNum = (num)=> {
    return new Promise((resolve, reject)=> {
        Employee.findAll({
          where: { employeeNum: num }
        }).then((data)=> { resolve(data[0]);
          }).catch(() => { reject("query returned 0 results"); });
    });
};

module.exports.getEmployeesByStatus = function (status) {
    return new Promise((resolve, reject)=> {
        Employee.findAll({
            where: { status: status }
          }).then((data)=> { resolve(data);
          }).catch(() => { reject("query returned 0 results"); });
    });
};


module.exports.getEmployeesByDepartment = (department)=> {
    return new Promise((resolve, reject)=> {
        Employee.findAll({
          where: { department: department }
        }).then((data)=> { resolve(data);
          }).catch(() => { reject("query returned 0 results"); });
    });
};

module.exports.getEmployeesByManager = (manager)=> {
    return new Promise((resolve, reject)=> {
        Employee.findAll({
          where: { employeeManagerNum: manager }
          }).then((data)=> { resolve(data);
          }).catch(() => { reject("query returned 0 results"); });
    });
};


module.exports.getDepartments = ()=> {
    return new Promise((resolve, reject)=> {
        Department.findAll().then((data)=> { resolve(data); })
        .catch((err) => { reject("query returned 0 results"); });
    });
}


module.exports.updateEmployee = (employeeData)=> {
    return new Promise((resolve, reject)=>{

        employeeData.isManager = (employeeData.isManager) ? true : false;

        for (var prop in employeeData) if (employeeData[prop] == '') employeeData[prop] = null;

        Employee.update(employeeData, {
          where: { employeeNum: employeeData.employeeNum }
        }).then(() => { resolve();
        }).catch((err) => { reject("unable to update employee"); console.log(err); });
    });
};

module.exports.addDepartment = function (departmentData) {
    return new Promise((resolve, reject)=> {
        for (var prop in departmentData) if(departmentData[prop] == '') departmentData[prop] = null;
        Department.create(departmentData).then(() => { resolve(); }).catch((e)=>{ reject("unable to create department"); });
    });
};

module.exports.updateDepartment = (departmentData)=> {
    return new Promise((resolve, reject)=> {
        for (var prop in departmentData) if (departmentData[prop] == '') departmentData[prop] = null;

        Department.update(departmentData, {
            where: { departmentId: departmentData.departmentId }
        }).then(() => { resolve();
        }).catch((e) => { reject("unable to update department"); });
    });

};

module.exports.getDepartmentById = (id)=> {
    return new Promise((resolve, reject)=> {
        Department.findAll({
            where: { departmentId: id }
        }).then((data)=> { resolve(data[0]);
        }).catch(() => { reject("query returned 0 results"); });
    });
};

module.exports.deleteEmployeeByNum = (empNum)=> {
    return new Promise((resolve, reject)=> {
        Employee.destroy({
            where: { employeeNum: empNum }
        }).then(()=> { resolve();
        }).catch((err) => { reject("unable to delete employee"); });
    });
}
