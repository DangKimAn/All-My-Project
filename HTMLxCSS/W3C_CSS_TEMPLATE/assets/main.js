var BuyTickets = document.querySelectorAll('.ticketbuy')
var ticket = document.querySelector('.buy-ticket')
var Closes = document.querySelectorAll('.close')
var Slider = document.querySelector('#Slider')
var Slider__Text = document.querySelector('.Slider--Text')
var Slider_css = [["https://www.w3schools.com/w3images/chicago.jpg","https://www.w3schools.com/w3images/la.jpg","https://www.w3schools.com/w3images/ny.jpg"],
           ['Chicago' , 'Los Angeles','New York'],
           ['Thank you, Chicago - A night we won\'t forget.','We had the best time playing at Venice Beach!','The atmosphere in New York is lorem ipsum.'] ]


    function Block()    
    {
        ticket.classList.add("open")
    }
    for (var BuyTicket of BuyTickets)
    {
        BuyTicket.addEventListener('click' ,Block);
    }

    function off ()
    {
        ticket.classList.remove("open")
    }
    for (var Close of Closes)
    {
        Close.addEventListener('click' ,off)
    }

    function backgroundSlider(index)
    {       
        setTimeout(()=>
        {
            if (index ===3)
                index=0
            Slider.style.background = `url(${Slider_css[0][index]})` 
            Slider__Text.innerHTML = `
                <div class="Child">
                    <h1>${Slider_css[1][index]}</h1>
                    <h2>${Slider_css[2][index]}</h2>
                </div>
            `
            backgroundSlider(index+1)
        } ,5000)
    }
backgroundSlider(0)
// Slider.style.background = `url(${img[0][2]})` 

// Slider.style.background = 'url(https://www.w3schools.com/w3images/chicago.jpg)'