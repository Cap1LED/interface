var dataset = []; // To store all data


//  This function updates the text box so we have
//  not just a visual representation but also a number
function updateText(){

}

// This function exports the current data to .csv
// and provides the user with a save dialog
function exportData() {
    let csvContent = "data:text/csv;charset=utf-8," 
    + dataset.map(e => e.join(",")).join("\n");
    var encodedUri = encodeURI(csvContent);
    window.open(encodedUri);
}

// This function clears the current data
function clearData() {
    location.reload()
}

// This function creates a POST to the API
// that then communicates with the a microcontroller
// on the selected address via I2C (20 bytes, 5xF32)
function dutyCycle() {
    data = {
        "board" : "1",
        "duty_cycle" : [0,0,0,0,0],
    }
    fetch("/dutyCycle", {
        method : 'POST',
        headers: {
            'Content-Type': 'application/json'
        },
          body: JSON.stringify(data)
    });
}

// This function creates a GET to the API
// that reads the current duty cycle and
// temperature via I2C for each board
// that was detected on startup
async function data(){
    await fetch("/data")
    .then(response => response.json())
    .then(data =>  {
        //Append the current data to the list of data points
        dataset.push([data.boards, data.duty_cycle, data.temperature]);
    });
}



// Copy-pasted from https://canvasjs.com/html5-javascript-dynamic-chart/
window.onload = function () {
    var dps = []; // Temperature datapoints
    var xVal = 0; // index
    var chart = new CanvasJS.Chart("chartContainer", {
        title :{
            text: "Temperature"
        },
        data: [{
            type: "line",
            dataPoints: dps
        }]
    });

    var updateInterval = 1000;
    var dataLength = 15; // number of dataPoints visible at any point
    
    var updateChart = async function () {
        // Poll API for current data
        await data();
        // Fill dps with data from dataset
        dps.push({
                x: xVal,
                y: dataset[xVal][2][0],
                });
        xVal++;
        if (dps.length > dataLength) {
            dps.shift();
        }
    
        chart.render();
    };
    
    updateChart();
    setInterval(function(){updateChart()}, updateInterval);
};

