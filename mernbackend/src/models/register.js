const mongoose= require("mongoose");
const user = new mongoose.Schema({
     userName:{
         type:String,
         requireed:true
     }
    //  positioncoord:{
    //      lattitude:{
    //          type:String
    //      },
    //      longitude:{
    //          type:String
    //      }
    //  }
})

const Register = new mongoose.model("Register",user);
module.exports=Register;