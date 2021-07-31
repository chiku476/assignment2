const express = require("express");
const path=require("path");
const hbs=require("hbs");
const app = express();
require("./db/conn"); 
const Register = require("./models/register");
const static_path = path.join(__dirname,"../public");
const partials_path = path.join(__dirname,"../templates/partials");
const template_path = path.join(__dirname,"../templates/views");
app.use(express.json());
app.use(express.urlencoded({extended:false}));
app.use(express.static(static_path));
app.set("view engine", "hbs");
app.set("views", template_path);  
const port = process.eventNames.PORT || 3000; 
app.get("/",(req,res)=>{
    res.render("index")
});
<script > 
const successCallback=(position)=>{
console.log(position.coords.latitude);
console.log(position.coords.longitude);
};
const errorCallback=(error)=>{
console.log(error);
};  
navigator.geolocation.getCurrentPosition(successCallback,errorCallback);
</script>
app.post("/", async (req,res)=>{
    try {

        const data= new Register({
            userName:req.body.fname,
            // positioncoord:position.lattitude:
        })
        const data2=await data.save();

        res.status(201).render("index");

    } catch (error) {
        res.status(400).send(error);
    } 
});

app.listen((port),()=>{
    console.log(`serwer is running at port no ${port}`);
});


// const lat = position.lattitude;
// const long = position.longitude;