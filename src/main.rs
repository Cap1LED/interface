use i2cdev::core::*;
use i2cdev::linux::{LinuxI2CMessage, LinuxI2CBus, LinuxI2CError};

use actix_web::{
    middleware, web, App, HttpResponse, HttpServer,
};
use actix_files as fs;
use serde::{Deserialize, Serialize};
use serde_with::{serde_as, DisplayFromStr};

#[derive(Serialize, Deserialize)]
struct UCData {
    boards: Vec<u8>,
    duty_cycle: Vec<Vec<f32>>,
    temperature: Vec<f32>,
    error: bool,
}

#[serde_as]
#[derive(Serialize, Deserialize)]
struct UCCommand{
    #[serde_as(as = "DisplayFromStr")]
    board: u8,
    #[serde_as(as = "Vec<Vec<DisplayFromStr>")]
    duty_cycle: Vec<f32>,
}

/// This function detects the microcontrollers via I2C and stores the addresses they responded on in shared state
async fn board_detect() {
    // TODO: Add I2C Code
    
}

/// This function reads the data from each board from I2C.
/// The data takes the form of
async fn get_data() -> HttpResponse {
    // TODO: Read the shared state we read with board_detect()
    
    // TODO: Read the I2C data about duty cycle
    
    // Dummy Response
    HttpResponse::Ok().json(&UCData{
        boards: vec![0x10],
        duty_cycle: vec![vec![10.0, 20.0, 30.0, 40.0]],
        temperature: vec![27.0],
        error: false,
    })
}

async fn set_duty_cycle(item: web::Json<UCCommand>) -> HttpResponse {
    HttpResponse::Ok().json(&UCData{
        boards: vec![0x10],
        duty_cycle: vec![vec![10.0, 20.0, 30.0, 40.0]],
        temperature: vec![27.0],
        error: false,
    })
}


/// This function creates the HTTP Server, defines the API and enables the logger
#[actix_web::main]
async fn main() -> std::io::Result<()> {
    std::env::set_var("RUST_LOG", "actix_web=info");
    env_logger::init();
    //TODO: Board detect
    HttpServer::new(|| {
        App::new()
            // enable logger
            .wrap(middleware::Logger::default())
            // create API routes
            .service(web::resource("/dutyCycle").route(web::post().to(set_duty_cycle)))
            .service(web::resource("/data").route(web::get().to(get_data)))
            //  serve static HTML
            .service(fs::Files::new("/", "./static").show_files_listing())
    })
    .bind("0.0.0.0:8080")?
    .run()
    .await
}
