cd "INSERT YOUR FOLDER HERE"

rmdir "BOSS/API"
rmdir "BOSS/Lib"
rmdir "BOSS/Messaging"

rmdir "BOSS-Task/API"
rmdir "BOSS-Task/Lib"
rmdir "BOSS-Task/Messaging"


mklink /d "BOSS\API" "..\BOSS-Common\API"
mklink /d "BOSS\Lib" "..\BOSS-Common\Lib"
mklink /d "BOSS\Messaging" "..\BOSS-Common\Messaging"

mklink /d "BOSS-Task\API" "..\BOSS-Common\API"
mklink /d "BOSS-Task\Lib" "..\BOSS-Common\Lib"
mklink /d "BOSS-Task\Messaging" "..\BOSS-Common\Messaging"

pause