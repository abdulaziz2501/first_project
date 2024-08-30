from django import forms
from .models import Elevator

class ElevatorStatusForm(forms.ModelForm):
    class Meta:
        model = Elevator
        fields = ['status']
