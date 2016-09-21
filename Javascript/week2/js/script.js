var userChoice;
var computerChoice;

function playStone(){
		$('#computer').css("background", "url('img/stone-r.png') no-repeat");
}

function playPaper(){
		$('#computer').css("background", "url('img/paper-r.png') no-repeat");
}

function playScissors(){
		$('#computer').css("background", "url('img/scissors-r.png') no-repeat");
}

function userPaper(){
	$('#player').css("background", "url('img/paper-l.png') no-repeat");
	userChoice = "paper";
	console.log(userChoice);
}

function userScissors(){
	$('#player').css("background", "url('img/scissors-l.png') no-repeat");
	userChoice = "scissors";

	console.log(userChoice);
}

function userStone(){
	$('#player').css("background", "url('img/stone-l.png') no-repeat");
	userChoice = "stone";
	console.log(userChoice);
}

function startPlay(){
	computerChoice = Math.random();

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
	compare();
}



var compare = function(){
	if(userChoice === "paper"){
		if(computerChoice === "stone") {
			console.log("win");	
				swal({   
				title: "You win!",   
				text: "Congratulation",   
				imageUrl: "img/win.png" });
			
		} else if(computerChoice === "scissors"){
			console.log("loose");
			swal({   
			title: "You Loose...",   
			text: "Try again?",   
			imageUrl: "img/loose.png" });			
		} else {
			console.log("draw");
			swal({   
			title: "It's A Draw!",   
			text: "Try again?",   
			imageUrl: "img/drawn.png" })			
		}
	} else if(userChoice === "scissors"){
		if(computerChoice === "paper") {
			console.log("win");
			swal({   
			title: "You win!",   
			text: "Congratulation",   
			imageUrl: "img/win.png" });
		} else if(computerChoice === "stone"){
			console.log("loose");
			swal({   
			title: "You Loose...",   
			text: "Try again?",   
			imageUrl: "img/loose.png" });			
		} else {
			console.log("draw");
			swal({   
			title: "It's A Draw!",   
			text: "Try again?",   
			imageUrl: "img/drawn.png" })			
		}
	} else if(userChoice === "stone"){
		if(computerChoice === "scissors") {
			console.log("win");
			swal({   
			title: "You win!",   
			text: "Congratulation",   
			imageUrl: "img/win.png" });
		} else if(computerChoice === "paper"){
			console.log("loose");
			swal({   
			title: "You Loose...",   
			text: "Try again?",   
			imageUrl: "img/loose.png" });			
		} else {
			console.log("draw");
			swal({   
			title: "It's A Draw!",   
			text: "Try again?",   
			imageUrl: "img/drawn.png" })			
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