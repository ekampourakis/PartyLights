#include <pgmspace.h>
char index_html[] PROGMEM = R"=====(
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <meta http-equiv="X-UA-Compatible" content="ie=edge">
    <title>Document</title>
    <link rel="stylesheet" href="https://stackpath.bootstrapcdn.com/bootstrap/4.3.1/css/bootstrap.min.css">
    <link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/5.11.2/css/all.min.css">
</head>
<body>

    <div class="container">
        <div class="row pt-4">
            <div class="col-12 text-center py-1">
                    <i class="fas fa-biohazard fa-3x"></i>
            </div>
            <div class="col-12 text-center">
                <h1>Party lights GUI</h1>
            </div>
        </div>
        <div class="row pt-4">
            <div class="col-3">
                <button type="button" class="btn btn-danger btn-lg w-100">Red</button>
            </div>
            <div class="col-3">
                <button type="button" class="btn btn-success btn-lg w-100">Green</button>
            </div>
            <div class="col-3">
                <button type="button" class="btn btn-primary btn-lg w-100">Blue</button>
            </div>
            <div class="col-3 d-flex align-items-center">
                <p class="m-0">Current color: <span>none</span></p>
            </div>
        </div>
        <div class="row pt-4">
            <div class="col-12">
                    <div class="dropdown w-100">
                        <button class="btn btn-secondary dropdown-toggle w-100" type="button" id="dropdownMenuButton" data-toggle="dropdown" aria-haspopup="true" aria-expanded="false">
                            Select mode
                        </button>
                        <div class="dropdown-menu w-100 dropdown-father" aria-labelledby="dropdownMenuButton">
                            <!-- Auto generated -->
                        </div>
                    </div>
            </div>
        </div>
        <div class="row pt-4">
            <div class="col-6 text-center my-auto">
                <div class="row">
                    <div class="col-12">
                            <button class="btn btn-secondary w-50 disabled" type="button">
                                    Autoplay &nbsp;<i class="fas fa-redo-alt"></i>
                            </button>
                    </div>
                    <div class="col-12 pt-2">
                            <button class="btn btn-secondary w-50" type="button">
                                Turn off &nbsp;<i class="fas fa-heart-broken"></i>
                            </button>
                    </div>
                </div>

            </div>
            <div class="col-6 d-flex justify-content-center align-items-center">
                 <div class="row">
                     <div class="col-12">
                            <label for="customRange1"><i class="fas fa-sun"></i> Brightness</label>
                            <input type="range" class="custom-range" id="customRange1">
                     </div>
                     <div class="col-12 py-2">
                            <label for="customRange1"><i class="far fa-clock"></i> Mode change interval</label>
                            <input type="range" class="custom-range" id="customRange1">
                     </div>
                     <div class="col-12">
                            <label for="customRange1"><i class="far fa-clock"></i> Color change interval</label>
                            <input type="range" class="custom-range" id="customRange1">
                     </div>
                 </div>
            </div>
        </div>
    </div>

    <script src="https://code.jquery.com/jquery-3.2.1.min.js"></script>
    <script src="https://cdnjs.cloudflare.com/ajax/libs/popper.js/1.12.9/umd/popper.min.js" integrity="sha384-ApNbgh9B+Y1QKtv3Rn7W3mgPxhU9K/ScQsAP7hUibX39j7fakFPskvXusvfa0b4Q" crossorigin="anonymous"></script>
    <script src="https://maxcdn.bootstrapcdn.com/bootstrap/4.0.0/js/bootstrap.min.js" integrity="sha384-JZR6Spejh4U02d8jOt6vLEHfe/JQGiRRSQQxSfFWpi1MquVdAyjUar5+76PVCmYl" crossorigin="anonymous"></script>
    <script>
        var modes = [];
        const forbidden = [9, 10, 16, 20, 23, 24, 25, 30, 31, 34, 35, 36, 37, 40, 41, 41, 45, 47, 48, 49, 50, 51, 52, 53, 54];
        fetch("http://192.168.1.8/modes")
            .then(function(res){
                return res.text();
            })
            .then(function(data) {
                data = data.slice(0, -1);
                data.split(",").forEach(function(mode, index) {
                    modes[index] = mode
                })
                forbidden.forEach(function (forbiddenMode) {
                    modes[forbiddenMode] = undefined;
                })
                modes.forEach(function (mode) {
                    if (mode) {
                        let element = document.createElement("a");
                        element.classList.add("dropdown-item");
                        element.innerText = mode;
                        document.querySelector(".dropdown-father").appendChild(element)
                    }
                })
            })

    </script>

</body>
</html>
)=====";