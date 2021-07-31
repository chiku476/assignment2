const successCallback=(position)=>{
    console.log(position.coords.latitude);
    console.log(position.coords.longitude);
  };
  const errorCallback=(error)=>{
    console.log(error);
    console.log("dd");
  };  
   navigator.geolocation.getCurrentPosition(successCallback,errorCallback);