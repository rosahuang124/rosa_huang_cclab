var userChoice;
var computerChoice;

function playStone(){
	if(computerChoice = "stone"){
		$('#computer').css("background", "url('img/stone-r.png') no-repeat");
	} 
}

function playPaper(){
	if(computerChoice = "paper"){
		$('#computer').css("background", "url('img/paper-r.png') no-repeat");
	} 
}

function playScissors(){
	if(computerChoice = "paper"){
		$('#computer').css("background", "url('img/scissors-r.png') no-repeat");
	} 
}

function userPaper(){
	$('#choose-paper').click($('#player').css("background", "url('img/paper-l.png') no-repeat"));
	var userChoice = "paper";
	console.log(userChoice);
}

function userScissors(){
	$('#choose-scissors').click($('#player').css("background", "url('img/scissors-l.png') no-repeat"));
	var userChoice = "scissors";
	console.log(userChoice);
}

function userStone(){
	$('#choose-stone').click($('#player').css("background", "url('img/stone-l.png') no-repeat"));
	var userChoice = "stone";
	console.log(userChoice);
}

function startPlay(){
	var computerChoice = Math.random();

	if(computerChoice < 0.34){
		computerChoice = "stone";
		playStone();
	} else if (computerChoice <= 0.67){
		computerChoice = "paper";
		playPaper();
	} else {
		computerChoice = "scissors";
		playScissors();
	}
	console.log("computer choose " + computerChoice)
}



var compare = function(){
	if(userChoice === "paper"){
		if(computerChoice === "stone") {
			console.log("win");
			// swal({   
			// title: "You win!",   
			// text: "Congratulation",   
			// imageUrl: "img/win.png" });
		} else if(computerChoice === "scissors"){
			console.log("loose");
			// swal({   
			// title: "You Loose...",   
			// text: "Try again?",   
			// imageUrl: "img/loose.png" });			
		} else {
			console.log("draw");
			// swal({   
			// title: "It's A Draw!",   
			// text: "Try again?",   
			// imageUrl: "img/drawn.png" })			
		}
	} else if(userChoice === "scissors"){
		if(computerChoice === "paper") {
			console.log("win");
			// swal({   
			// title: "You win!",   
			// text: "Congratulation",   
			// imageUrl: "img/win.png" });
		} else if(computerChoice === "stone"){
			console.log("loose");
			// swal({   
			// title: "You Loose...",   
			// text: "Try again?",   
			// imageUrl: "img/loose.png" });			
		} else {
			console.log("draw");
			// swal({   
			// title: "It's A Draw!",   
			// text: "Try again?",   
			// imageUrl: "img/drawn.png" })			
		}
	} else if(userChoice === "stone"){
		if(computerChoice === "scissors") {
			console.log("win");
			// swal({   
			// title: "You win!",   
			// text: "Congratulation",   
			// imageUrl: "img/win.png" });
		} else if(computerChoice === "paper"){
			console.log("loose");
			// swal({   
			// title: "You Loose...",   
			// text: "Try again?",   
			// imageUrl: "img/loose.png" });			
		} else {
			console.log("draw");
			// swal({   
			// title: "It's A Draw!",   
			// text: "Try again?",   
			// imageUrl: "img/drawn.png" })			
		}
	}
}




var main = function(){
	console.log("get start!");

	$('#choose-paper').click(function(){
		userPaper(); 
		startPlay();
	});

	$('#choose-scissors').click(function(){
		userScissors(); 
		startPlay();
	});

	$('#choose-stone').click(function(){
		userStone(); 
		startPlay();
	});
};


$(document).ready(main);