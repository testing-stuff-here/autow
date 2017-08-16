window.onload= function(){
	window.afdp.readyToDisplay();
};

function callAction(pAction)
{
	try{
		window.afdp.simpleCallOutActionWithName(pAction); 
	}catch(e)
	{
		alert(e);
	}
}