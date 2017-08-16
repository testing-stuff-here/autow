/**
 * Function to fire off Google Event upon survey submission
 */
function surveyEventTracker() {
  if(document.getElementById('edit-radios-0').checked) {
    ga('send', 'event', 'Print Subscriber Poll', 'Print Subscriber');
  }
  if(document.getElementById('edit-radios-1').checked) {
    ga('send', 'event', 'Print Subscriber Poll', 'Digital Subscriber');
  }
  if(document.getElementById('edit-radios-2').checked) {
    ga('send', 'event', 'Print Subscriber Poll', 'Not a Subscriber');
  }
}
