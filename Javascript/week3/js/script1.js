var APIKey = 'AIzaSyDTkuPsw9awMJ9wFKvwU9Gm2_sDVtyYSGs';

//showResults
function displayResults(videos) {
        var html = "";
        $.each(videos, function (index, video) {
            // Append results li to ul
            console.log(video.snippet.title);
            console.log(video.snippet.thumbnails.high.url);
            html = html + "<li><p class='line-clamp'>" + video.snippet.title +
                "</p><a target='_blank' href='https://www.youtube.com/watch?v=" + video.id.videoId + "'><img src='" +  video.snippet.thumbnails.high.url + "'/></a></li>" ;
        });
        $("#search-results ul").html(html);
}

//getResults
var getResults = function(){

    var myUrl = 'https://www.googleapis.com/youtube/v3/search?part=snippet&key=[AIzaSyDTkuPsw9awMJ9wFKvwU9Gm2_sDVtyYSGs]'


    //run the ajax call and load 
    $.ajax({
        url: myUrl,
        dataType: "jsonp",
        success: function(response){
            displayResults(data.items);
            }

    })

    // $.getJSON("https://www.googleapis.com/youtube/v3/search",
    //         {
    //             "part": "snippet",
    //             "key": "AIzaSyDTkuPsw9awMJ9wFKvwU9Gm2_sDVtyYSGs",
    //             "q": searchTerm,
    //             "maxResults": 15
    //         },
    //         function (data) {
    //             if (data.pageInfo.totalResults == 0) {
    //                 alert("No results!");
    //             }
    //             // If no results, empty the list
    //             displayResults(data.items);
    //         }
    //     );

    // request.execute(showResults);
    // console.log("getResults finished!");
}


//init
var init = function(){
    console.log("What's video do you want?");
}

$(document).ready(function(){
    init();//call init() function when the page loads

    $('#submit').click(function(e){
        e.preventDefault();
        getResults();
    })
});