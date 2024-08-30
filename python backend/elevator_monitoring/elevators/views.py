from django.shortcuts import render, redirect
from .models import Elevator
from .forms import ElevatorStatusForm
from django.utils import timezone

def index(request):
    elevators = Elevator.objects.all()
    return render(request, 'elevators/index.html', {'elevators': elevators})

def update_status(request, pk):
    elevator = Elevator.objects.get(pk=pk)
    if request.method == 'POST':
        form = ElevatorStatusForm(request.POST, instance=elevator)
        if form.is_valid():
            form.save()
            return redirect('index')
    else:
        form = ElevatorStatusForm(instance=elevator)
    return render(request, 'elevators/update_status.html', {'form': form, 'elevator': elevator})
